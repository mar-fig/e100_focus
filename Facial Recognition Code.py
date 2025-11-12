import cv2

# Load the face detection model
face_cascade = cv2.CascadeClassifier(
    "/Users/marcelo/Documents/EngineeringProject/haarcascade_frontalface_default.xml"
)

# Access the webcam (0 = built-in, 1 = external)
cap = cv2.VideoCapture(1)

while True:
    ret, frame = cap.read()
    if not ret:
        print("Failed to grab frame")
        break

    # Convert to grayscale for detection
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Detect faces
    faces = face_cascade.detectMultiScale(
        gray,
        scaleFactor=1.1,
        minNeighbors=5,
        minSize=(30, 30)
    )

    # Draw rectangles around detected faces
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)

    cv2.imshow("Face Detection", frame)

    # Wait for key press
    key = cv2.waitKey(1) & 0xFF

    # Press 'q' to quit
    if key == ord('q'):
        break

    # Press 'w' to print width/height of detected faces
    if key == ord('w'):
        if len(faces) == 0:
            print("No faces detected.")
        else:
            for i, (x, y, w, h) in enumerate(faces):
                print(f"Face {i+1}: width = {w}, height = {h}")

cap.release()
cv2.destroyAllWindows()