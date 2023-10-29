# Medical Clinic Scheduling System

The Medical Clinic Scheduling System automates scheduling services for doctors and patients. The system manages doctor check-in, check-out, and patient check-in, check-out functionalities. Below are the details and functionalities of the system:

## Doctor Check-in and Check-out:

- **Check-in:**
  - The system prompts the user for the doctor's name, room number, and specialty code.
  - If the room is available, the doctor is assigned to the room; otherwise, an error message is displayed.
  
- **Check-out:**
  - The doctor checks out, and the examination room becomes free for the next assignment.

## Patient Check-in and Check-out:

- **Check-in:**
  - The system prompts the user for the patient's name, age, specialty code requested, and emergency indication.
  - The system assigns a doctor to the patient based on specific rules:
    1. Patients under 16 years old are assigned to pediatricians.
    2. Patients aged 16 and older are assigned to doctors based on their requested specialty. If no doctor with the requested specialty is available, the patient is assigned to a general practitioner (GP) or any available doctor.
    3. Patients are assigned to doctors with the shortest waiting list within the requested specialty.
  - Emergency cases are prioritized and moved to the front of the waiting list.

- **Check-out:**
  - The patient checks out, and the assigned doctor becomes available to see the next patient if there is anyone in the waiting list.

## User Interaction

- The program prompts the users with the following messages:
  - Type D for Doctor or P for Patient:
  - Type I for check-in or O for checkout:

## Specialty Codes

- Specialty codes are as follows:
  - Pediatrics: PED
  - General Practice: GEN (or GP)
  - Internal Medicine: INT
  - Cardiology: CAR
  - Surgeon: SUR
  - Obstetrics: OBS
  - Psychiatry: PSY
  - Neurology: NEU
  - Orthopedics: ORT
  - Dermatology: DET
  - Ophthalmology: OPT
  - Ear, Nose, and Throat: ENT

## Assumptions

1. There are 100 examination rooms, each with an attached waiting list.
2. No patient leaves without checking out.
3. Patients are seen in the order they are added to the waiting list.
4. The clinic operates 24/7.
5. If a doctor checks out while patients are waiting, the patients are reassigned to other available doctors.

## Data Structures

- The system uses an array of records to represent examination rooms, each with an attached waiting list. Patients are managed as queues within the waiting lists.

## Output

- The system outputs confirmation messages, room assignments, error messages, and good-bye messages based on the user's actions.
- All requests and messages are logged in a transaction file called `trans.out`.

### Note:

This system provides a foundation for managing the clinic's scheduling services. It allows doctors and patients to check in and out seamlessly, ensuring efficient utilization of resources and patient care.
