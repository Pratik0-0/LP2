import tkinter as tk
from tkinter import scrolledtext
from datetime import datetime

# -------------------------------
# Simple Hospital Expert Chatbot
# -------------------------------

class HospitalChatbot:
    def __init__(self, root):
        self.root = root
        self.root.title("Hospital Expert System Chatbot")
        self.root.geometry("650x500")
        self.root.config(bg="#f0f4f7")

        # Heading
        heading = tk.Label(
            root,
            text="Hospital Expert System Chatbot",
            font=("Arial", 18, "bold"),
            bg="#2c7fb8",
            fg="white",
            pady=10
        )
        heading.pack(fill=tk.X)

        # Chat Area
        self.chat_area = scrolledtext.ScrolledText(
            root,
            wrap=tk.WORD,
            font=("Arial", 12),
            state='disabled',
            bg="white"
        )
        self.chat_area.pack(padx=10, pady=10, fill=tk.BOTH, expand=True)

        # Input Frame
        input_frame = tk.Frame(root, bg="#f0f4f7")
        input_frame.pack(fill=tk.X, padx=10, pady=5)

        self.user_input = tk.Entry(
            input_frame,
            font=("Arial", 12)
        )
        self.user_input.pack(side=tk.LEFT, fill=tk.X, expand=True, padx=(0, 10))
        self.user_input.bind("<Return>", self.process_message)

        send_btn = tk.Button(
            input_frame,
            text="Send",
            font=("Arial", 11, "bold"),
            bg="#2c7fb8",
            fg="white",
            command=self.process_message
        )
        send_btn.pack(side=tk.RIGHT)

        # Welcome Message
        self.bot_message(
            "Hello! I am the Hospital Expert Chatbot.\n"
            "I can help with:\n"
            "- Doctor availability\n"
            "- Appointment booking\n"
            "- Hospital timings\n"
            "- Emergency guidance\n"
            "- Basic symptom advice\n"
            "Type your question below."
        )

    # Display Bot Message
    def bot_message(self, message):
        self.chat_area.config(state='normal')
        self.chat_area.insert(tk.END, f"\nBot: {message}\n")
        self.chat_area.config(state='disabled')
        self.chat_area.see(tk.END)

    # Display User Message
    def user_message(self, message):
        self.chat_area.config(state='normal')
        self.chat_area.insert(tk.END, f"\nYou: {message}\n")
        self.chat_area.config(state='disabled')
        self.chat_area.see(tk.END)

    # Main Logic
    def get_response(self, user_text):

        text = user_text.lower()

        # Greetings
        if any(word in text for word in ["hello", "hi", "hey"]):
            return "Hello! How can I help you today?"

        # Appointment
        elif "appointment" in text:
            return (
                "Appointments are available from 9 AM to 5 PM.\n"
                "Please visit the reception desk or call: 9876543210."
            )

        # Doctor availability
        elif "doctor" in text:
            return (
                "Available Doctors:\n"
                "1. Dr. Sharma - Cardiologist\n"
                "2. Dr. Mehta - General Physician\n"
                "3. Dr. Patel - Orthopedic"
            )

        # Hospital timings
        elif "timing" in text or "open" in text:
            return "Hospital timings are 24/7 for emergency services."

        # Fever advice
        elif "fever" in text:
            return (
                "For fever:\n"
                "- Drink plenty of fluids\n"
                "- Take rest\n"
                "- Consult a doctor if temperature exceeds 102°F"
            )

        # Headache advice
        elif "headache" in text:
            return (
                "For headache:\n"
                "- Rest in a quiet room\n"
                "- Drink water\n"
                "- If pain persists, consult a doctor."
            )

        # Emergency
        elif "emergency" in text:
            return (
                "For emergencies call ambulance service at 108 immediately."
            )

        # Date and time
        elif "time" in text or "date" in text:
            now = datetime.now()
            return now.strftime("Current Date & Time: %d-%m-%Y %H:%M:%S")

        # Exit
        elif "bye" in text or "exit" in text:
            return "Thank you for using Hospital Expert Chatbot. Stay healthy!"

        # Unknown queries
        else:
            return (
                "Sorry, I can only answer basic hospital-related questions."
            )

    # Process User Input
    def process_message(self, event=None):
        user_text = self.user_input.get().strip()

        if user_text == "":
            return

        self.user_message(user_text)

        response = self.get_response(user_text)
        self.bot_message(response)

        self.user_input.delete(0, tk.END)


# Run Application
if __name__ == "__main__":
    root = tk.Tk()
    app = HospitalChatbot(root)
    root.mainloop()