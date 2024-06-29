import pyautogui
import webbrowser
from  time import sleep

webbrowser.open_new('https://mail.google.com/mail/u/0/?tab=rm&ogbl#inbox')
sleep(2)



try:
    location = None
    while location is None:
        location = pyautogui.locateOnScreen('choice.png')
        sleep(2)
except pyautogui.ImageNotFoundException:
    print('choice not found !')
    exit()

sleep(2)
pyautogui.click(location.left+10, location.top+8, duration=1) 
sleep(2)



try:
    location = None
    while location is None:
        location = pyautogui.locateOnScreen('read.png')
        sleep(2)
except pyautogui.ImageNotFoundException:
    print('read not found !')
   
sleep(2)
pyautogui.click(location.left, location.top+5, duration=1)
