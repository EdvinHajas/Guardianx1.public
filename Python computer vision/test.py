import cv2
import mediapipe as mp

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    img = cv2.resize(frame, (0, 0), fx=1, fy=1)
    image = cv2.circle(img, (300, 300), 50, (125, 125, 0), 3)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    Thresh = cv2.adaptiveThreshold(gray, 255, cv2.ADAPTIVE_THRESH_MEAN_C,
                                   cv2.THRESH_BINARY_INV, 11, 2)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    cv2.imshow('frame', image)
    cv2.imshow('Thresh', Thresh)
    cv2.imshow('hsv', hsv)

    if cv2.waitKey(1) == ord('e'):
        break

cap.release()
cv2.destroyAllWindows()