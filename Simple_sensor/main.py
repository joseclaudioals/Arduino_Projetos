import serial
import time
import pyautogui

def testeserial():
    portcom = 'COM7'
    baud = 9600

    try:
        arduino = serial.Serial(portcom, baud, timeout = 2)
        print(f"Conectado a: {arduino.name}")

        time.sleep(1)

        while True:
            if arduino.in_waiting>0:
                mensagem = arduino.readline()

                try:
                    mensagem = mensagem.decode('utf-8').strip()
                except UnicodeError:
                    continue
                print(f"Recebido: {mensagem}")

                if mensagem == "objeto_detectado":
                    pyautogui.hotkey('win', 'm')

                if mensagem=="botao_pressionado":
                    print("programa encerrando")
                    break

    except serial.SerialException as e:
        print(f"erro: {e}")
    except FileNotFoundError as e:
        print(f"erro: {e}")
    except PermissionError as e:
        print(f"erro: {e}")


if __name__ == "__main__":
    testeserial()