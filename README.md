
# Sleep-Inducer

# Overview

The Sleep Inducer System is a C++ program designed to manage inmate records and dorm allocations in a correctional facility. The system assigns music channels based on inmate earpod IDs and music IDs while ensuring that inmates with the same music preferences are allocated to the same dormitory.

# Features

- Record Management: The system manages inmate records using a struct called Record that stores inmate names, earpod IDs, music IDs, and dormitory allocations.

- Dormitory Allocation: Inmates with the same music preferences are allocated to the same dormitory, enhancing their experience and fostering a peaceful environment.

- Music Channel Assignment: The system allocates music channels to inmates based on their earpod IDs and music IDs, ensuring personalized music experiences.

- Backup Channels: The system includes a backup mechanism to store earpod IDs for emergency channel allocation.

# Code Structure

The code is organized into the following components:

- Structs: Includes Record struct for inmate data and BackupChannels struct for emergency channel allocation.

- Data Management: Functions to manage inmate records, dormitory allocations, and music channel assignments.

- Sorting Algorithm: Algorithm to sort earpod IDs and music IDs to allocate inmates with similar preferences to the same dormitory.

- Main Program: Entry point of the program with sample data for testing and demonstration.

# Usage

Utilize the Sleep Inducer System to efficiently manage inmate records, allocate dormitories based on music preferences, and assign personalized music channels.

The following steps outline the typical usage scenario:

- Input Inmate Records: Input inmate data including names, earpod IDs, and music IDs using the provided functions.

- Sort Inmates into Dormitories: Utilize the sorting algorithm to group inmates with similar music preferences into the same dormitory. This step promotes a harmonious living environment among inmates.

- Allocate Music Channels: Allocate music channels to inmates based on their earpod IDs and music IDs. The system ensures that each inmate receives a personalized music experience tailored to their preferences.

- Monitor and Manage Allocations: Monitor dormitory allocations and music channel assignments, making adjustments as necessary to optimize the inmate experience.
## Usage/Examples

This program is a Tool which takes 2 files as user input which are 

- 'Inmate_records.txt' 
- 'Dorm_records.txt'


The format for 'Inmate_records.txt' as Input/Output taken in the following program is 
	
	DormA DormB DormC DormD DormE 
	Eswar      1000  21:32  20:46  22:27  20:05  20:34  21:39  22:00  27  4
    Krupa      1001  22:10  20:38  20:00  22:34  20:23  21:02  20:02  21  3
    Ravi       1002  21:39  22:17  21:09  20:17  20:13  20:45  20:47  39  2
	Shetty     1003  21:26  21:03  22:18  22:51  22:15  22:47  20:54  13  1
	Uttam      1004  22:28  21:33  21:28  20:28  22:55  20:33  22:12  44  2
	Charan     1005  22:37  22:09  22:39  22:41  21:09  22:39  21:44  36  1
	Prabhas    1006  22:13  22:51  22:27  21:14  20:32  21:19  21:18  11  4
	Eswar      1007  22:12  22:58  21:56  21:51  22:49  20:27  20:31  12  3
	Kumar      1008  22:12  22:58  21:44  21:55  20:25  21:37  21:56  53  5
	Rishi      1009  20:01  22:51  22:36  21:31  20:25  21:01  22:08  35  1
	Madhu      1010  22:49  22:42  21:13  22:20  20:13  20:17  21:49  15  2
	Niharaika  1011  21:50  21:35  20:52  20:05  21:19  22:21  20:27  53  4
	Nithin     1012  22:30  20:39  21:04  20:30  21:30  22:32  21:04  47  4
	Lohitha    1013  20:48  21:19  20:44  20:10  21:39  21:32  21:23  22  2
	Rishi      1014  21:31  22:38  22:09  22:03  20:04  22:47  22:45  42  5
	Hari       1015  21:50  22:12  20:36  21:59  22:22  22:16  20:40  43  4
	Vinobha    1016  20:05  21:36  21:59  20:42  21:24  20:15  22:44  39  4
	Aarohi     1017  21:24  22:23  22:47  22:18  21:50  21:21  20:00  28  4
	Lokesh     1018  20:32  22:17  22:19  22:18  21:51  22:52  20:09  43  2
	Kumar      1019  20:27  20:17  22:37  21:51  20:26  22:11  21:33  54  3


The format for 'Dorm_records.txt' as Input/Output in the following program is

	
	DormA DormB DormC DormD DormE 
	10 11 12 13 14 
	1 2 3 4 5

## Installation

To utilize the Sleep Inducer System:
```To run the Sleep Inducer System: 
	https://github.com/your_username/sleep-inducer-system.git.

	Compile the source code using a C++ compiler compatible with your system 
	specifications.

	Execute the generated executable file to launch the Sleep Inducer System 
	application.
```





    
## Running Tests

Example Test Case for your understanding.

```bash
Enter number of inmates:
25
You have stated there are 25 inmates.
Enter number of Dorms:
5
You have kept 5 Dorms for inmates to stay.
Enter number of people per dorm:
5
You have set 5 people per dorm.
Thank you.. You can accomdate sucessfully.
Enter number of channels:

5
You have set 5 channels.
Do you want to randomize the sleep time of inmates? Enter 'Y' or 'y' for yes, press any other character to choose as no: y
Sleep time will be randomized
Do you want to randomize the Dorms of inmates? Enter 'Y' or 'y' for yes, press any other character to choose as no: y
Dorms will be randomized
How much incrementation do you want to take every cycle? Enter the value: 30
The time will increment every 30 minutes.
There are currently 25 inmates in 5 dorms

The Present Inmates average Sleep times are:
Krupa     : 20:28
Niharaika : 20:33
Aarohi    : 20:18
Rishi     : 20:33
Rishik    : 21:38
Arjun     : 21:30
Suhas     : 21:25
Jayanth   : 21:31
Uttam     : 21:32
Siddharth : 20:34
Mukesh    : 20:24
Kriti     : 20:34
Kumar     : 21:29
Rajamouli : 21:31
Venkat    : 21:27
Sai       : 20:24
Reddy     : 20:24
Trivikram : 21:32
Aadi      : 21:31
Aadi      : 21:25
Vinobha   : 21:28
Sai       : 20:16
Suhas     : 20:28
Lohitha   : 20:23
Venkat    : 20:26

Time taken by each inmate to fall asleep are:
Krupa     : 31 minutes
Niharaika : 49 minutes
Aarohi    : 33 minutes
Rishi     : 57 minutes
Rishik    : 25 minutes
Arjun     : 11 minutes
Suhas     : 46 minutes
Jayanth   : 19 minutes
Uttam     : 34 minutes
Siddharth : 59 minutes
Mukesh    : 46 minutes
Kriti     : 29 minutes
Kumar     : 37 minutes
Rajamouli : 57 minutes
Venkat    : 40 minutes
Sai       : 41 minutes
Reddy     : 10 minutes
Trivikram : 43 minutes
Aadi      : 52 minutes
Aadi      : 58 minutes
Vinobha   : 41 minutes
Sai       : 31 minutes
Suhas     : 46 minutes
Lohitha   : 55 minutes
Venkat    : 47 minutes

Music for each inmate will Automatically stop at:
Krupa     : 20:59
Niharaika : 21:22
Aarohi    : 20:51
Rishi     : 21:30
Rishik    : 22:03
Arjun     : 21:41
Suhas     : 22:11
Jayanth   : 21:50
Uttam     : 22:06
Siddharth : 21:33
Mukesh    : 21:10
Kriti     : 21:03
Kumar     : 22:06
Rajamouli : 22:28
Venkat    : 22:07
Sai       : 21:05
Reddy     : 20:34
Trivikram : 22:15
Aadi      : 22:23
Aadi      : 22:23
Vinobha   : 22:09
Sai       : 20:47
Suhas     : 21:14
Lohitha   : 21:18
Venkat    : 21:13

Currently the time is: 20:00
30 minutes have passed...

Currently the time is: 20:30
Music Channel 10 has been allocated for EarpodID 1000 with MusicID 1
Music Channel 11 has been allocated for EarpodID 1002 with MusicID 4
Music Channel 12 has been allocated for EarpodID 1010 with MusicID 3
Multiple People in same Dorm with same MusicID Detected!
Music Channel 12 has also been allocated for EarpodID 1015 with MusicID 3
Multiple People in same Dorm with same MusicID Detected!
Music Channel 10 has also been allocated for EarpodID 1016 with MusicID 1
Multiple People in same Dorm with same MusicID Detected!
Music Channel 11 has also been allocated for EarpodID 1021 with MusicID 4
Multiple People in same Dorm with same MusicID Detected!
Music Channel 12 has also been allocated for EarpodID 1022 with MusicID 3
Music Channel 13 has been allocated for EarpodID 1023 with MusicID 2
Multiple People in same Dorm with same MusicID Detected!
Music Channel 12 has also been allocated for EarpodID 1024 with MusicID 3
30 minutes have passed...

Currently the time is: 21:00
Music has stopped playing for Krupa      at 20:59
Multiple People in same Dorm with same MusicID Detected!
Music Channel 11 has also been allocated for EarpodID 1001 with MusicID 4
Music has stopped playing for Aarohi     at 20:51
Multiple People in same Dorm with same MusicID Detected!
Music Channel 10 has also been allocated for EarpodID 1003 with MusicID 1
Multiple People in same Dorm with same MusicID Detected!
Music Channel 12 has also been allocated for EarpodID 1009 with MusicID 3
Music is currently playing for Mukesh   
Multiple People in same Dorm with same MusicID Detected!
Music Channel 12 has also been allocated for EarpodID 1011 with MusicID 3
Music is currently playing for Sai      
Music has stopped playing for Reddy      at 20:34
Music has stopped playing for Sai        at 20:47
Music is currently playing for Suhas    
Music is currently playing for Lohitha  
Music is currently playing for Venkat   
30 minutes have passed...

Currently the time is: 21:30
Music has stopped playing for Niharaika  at 21:22
Music Channel 11 has become free.
Music has stopped playing for Rishi      at 21:30
Music Channel 10 has become free.
Music Channel 10 has been allocated for EarpodID 1005 with MusicID 5
Music Channel 11 has been allocated for EarpodID 1006 with MusicID 1
Music is currently playing for Siddharth
Music has stopped playing for Mukesh     at 21:10
Music has stopped playing for Kriti      at 21:03
Multiple People in same Dorm with same MusicID Detected!
Music Channel 13 has also been allocated for EarpodID 1012 with MusicID 2
Multiple People in same Dorm with same MusicID Detected!
Music Channel 12 has also been allocated for EarpodID 1014 with MusicID 3
Music has stopped playing for Sai        at 21:05
Multiple People in same Dorm with same MusicID Detected!
Music Channel 10 has also been allocated for EarpodID 1019 with MusicID 5
Multiple People in same Dorm with same MusicID Detected!
Music Channel 10 has also been allocated for EarpodID 1020 with MusicID 5
Music has stopped playing for Suhas      at 21:14
Music has stopped playing for Lohitha    at 21:18
Music has stopped playing for Venkat     at 21:13
30 minutes have passed...

Currently the time is: 22:00
Multiple People in same Dorm with same MusicID Detected!
Music Channel 12 has also been allocated for EarpodID 1004 with MusicID 3
Music has stopped playing for Arjun      at 21:41
Multiple People in same Dorm with same MusicID Detected!
Music Channel 10 has also been allocated for EarpodID 1005 with MusicID 5
Music is currently playing for Suhas    
Multiple People in same Dorm with same MusicID Detected!
Music Channel 11 has also been allocated for EarpodID 1007 with MusicID 1
Music Channel 14 has been allocated for EarpodID 1008 with MusicID 4
Music has stopped playing for Siddharth  at 21:33
Music is currently playing for Kumar    
Multiple People in same Dorm with same MusicID Detected!
Music Channel 14 has also been allocated for EarpodID 1013 with MusicID 4
Music is currently playing for Venkat   
Multiple People in same Dorm with same MusicID Detected!
Music Channel 13 has also been allocated for EarpodID 1017 with MusicID 2
Multiple People in same Dorm with same MusicID Detected!
Music Channel 11 has also been allocated for EarpodID 1018 with MusicID 1
Music is currently playing for Aadi     
Music is currently playing for Vinobha  
30 minutes have passed...

Currently the time is: 22:30
Music has stopped playing for Rishik     at 22:03
Music has stopped playing for Arjun      at 21:41
Music has stopped playing for Suhas      at 22:11
Music has stopped playing for Jayanth    at 21:50
Music has stopped playing for Uttam      at 22:06
Music has stopped playing for Kumar      at 22:06
Music has stopped playing for Rajamouli  at 22:28
Music Channel 14 has become free.
Music has stopped playing for Venkat     at 22:07
Music Channel 12 has become free.
Music has stopped playing for Trivikram  at 22:15
Music Channel 13 has become free.
Music has stopped playing for Aadi       at 22:23
Music Channel 11 has become free.
Music has stopped playing for Aadi       at 22:23
Music has stopped playing for Vinobha    at 22:09
Music Channel 10 has become free.
30 minutes have passed...

Currently the time is: 23:00
30 minutes have passed...
Inmate records updated and saved to 'Inmate_records_updated.txt'.


...Program finished with exit code 0
Press ENTER to exit console.
```


## Contributers

The Sleep Inducer System is a collaborative effort, and we extend our gratitude to the following contributors for their valuable contributions:

    Rishik Yalamanchili
    Lingampalli Venkata Subramanyam 
	Vraj Chandrakant Patel
	Aaditya Thakkar