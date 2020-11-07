import argparse
import imutils
import cv2

ap = argparse.ArgumentParser()
ap.add_argument("-i","--image",required=True,help="path to the input image")
args = vars(ap.parse_args())


image = cv2.imread(args["image"])
gray = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
cv2.imshow('gray',gray)
cv2.waitKey(0)

blurred = cv2.GaussianBlur(gray,(5,5),0)
cv2.imshow('blurred',blurred)
cv2.waitKey(0)

thresh = cv2.threshold(blurred,60,255,cv2.THRESH_BINARY)[1]
cv2.imshow('thresh',thresh)
cv2.waitKey(0)
cv2.destroyAllWindows()
