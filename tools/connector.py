import serial
import time
import threading
import sys

class SerialPingPong:
    def __init__(self, port, baudrate=115200, timeout=1):
        """
        Initialize serial communication
        
        Args:
            port (str): Serial port (e.g., 'COM17' on Windows, '/dev/ttyUSB0' on Linux)
            baudrate (int): Baud rate for communication
            timeout (float): Read timeout in seconds
        """
        try:
            self.ser = serial.Serial(port, baudrate, timeout=timeout)
            self.running = False
            print(f"Serial port {port} opened successfully at {baudrate} baud")
        except serial.SerialException as e:
            print(f"Error opening serial port: {e}")
            sys.exit(1)

    def send_message(self, message):
        """Send a message over serial"""
        try:
            self.ser.write((message + '\n').encode('utf-8'))
            print(f"Sent: {message}")
        except Exception as e:
            print(f"Error sending message: {e}")

    def send_etx(self):
        """Send a message over serial"""
        try:
            self.ser.write(b'\x03')
            print(f"Sent: ETX")
        except Exception as e:
            print(f"Error sending message: {e}")

    def receive_message(self):
        """Receive a message from serial"""
        try:
            if self.ser.in_waiting > 0:
                data = self.ser.read(1)  # Read one byte
                if data == b'\x04':
                    print(f"Goodbye")
                    return "quit"

                # For regular text, read the full line
                if data == b'\n' or data.isalpha():
                    self.ser.timeout = 0.1
                    remaining = self.ser.readline()
                    message = (data + remaining).decode('utf-8').strip()
                    if message:
                        print(f"Received: {message}")
                        return message
        except Exception as e:
            print(f"Error receiving message: {e}")
        return None

    def interactive_mode(self):
        """Interactive mode for manual testing"""
        print("Interactive mode started. Type 'quit' to exit.")
        print("Commands: ping, pong, or any custom message")

        # Start receiver thread
        receiver_thread = threading.Thread(target=self.continuous_receiver)
        receiver_thread.daemon = True
        receiver_thread.start()

        while receiver_thread.is_alive():
            try:
                user_input = input("Enter message: ").strip()
                if user_input.lower() == 'quit':
                    self.send_etx()
                elif user_input:
                    self.send_message(user_input)
            except KeyboardInterrupt:
                print("\nExiting...")
                break

    def continuous_receiver(self):
        """Continuously receive messages (for interactive mode)"""
        while True:
            received = self.receive_message()
            if received and received.lower() == "quit":
                break
            time.sleep(0.01)

    def close(self):
        """Close serial connection"""
        self.running = False
        if self.ser.is_open:
            self.ser.close()
            print("Serial port closed")

def main():
    # Configuration
    PORT = '/dev/ttyACM0'
    BAUDRATE = 115200

    # Create serial communication object
    comm = SerialPingPong(PORT, BAUDRATE)

    try:
        comm.interactive_mode()
    except KeyboardInterrupt:
        print("\nProgram interrupted by user")
    except Exception as e:
        print(f"Error: {e}")
    finally:
        comm.close()

if __name__ == "__main__":
    main()