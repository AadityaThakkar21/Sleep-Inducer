
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

- The time complexity and Space complexity of the program is O(n) and O(m)

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

## Pseudocode


	Include necessary libraries:
    <iostream>
    <fstream>
    <cstdlib>
    <ctime>
    <vector>
    <sstream>
    <cmath>
    <iomanip>
    <algorithm>

	Define constants:
    MAX_DORMS = 100
    MAX_INMATES_PER_DORM = 100

	Define struct ChannelControl:
    Properties: occupied, dormIndex, musicID, earpodID (vector of int)
    Constructor: initialize occupied as false, dormIndex as -1, musicID as -1, and  	earpodID as empty vector

	Include standard and vector namespaces:
    using namespace std;
    using std::left;
    
	Define class Time:
    Properties: hours, minutes
    Constructor:
        Time(): Set hours to 0, minutes to 0
        Time(int h, int m): Set hours to h, minutes to m

    Method set(int h, int m):
        Set hours to h
        Set minutes to m

    Method check():
        If hours is greater than or equal to 24:
            Subtract 24 from hours

    Method printTime() const:
        Print hours
        Print ":"
        If minutes is less than 10:
            Print "0"
        Print minutes

    Method incrementMinutes(int minutesToAdd):
        Add minutesToAdd to minutes
        If minutes is greater than or equal to 60:
            Calculate remaining minutes using minutes %= 60
            Increment hours by one

    Method isWithinRange() const:
        Return true if hours are between 20 and 23 (inclusive), else return false

    Method isMidnight() const:
        Return true if hours are 24 and minutes are 0, else return false

    Method operator>=(const Time& other) const:
        If hours are greater than other.hours:
            Return true
        Else if hours are equal to other.hours and minutes are greater than or equal to other.minutes:
            Return true
        Else:
            Return false

	Define function randomInt(min, max) returns int:
    Return min + rand() % (max - min + 1)

	Define function generateRandomTime(Time& sleepTime):
    Set sleepTime using randomInt(20, 22) for hours and randomInt(0, 59) for minutes

	Define function generateInmateRecords(int N):
    Open output file "Inmate_records.txt"
    If file cannot be opened:
        Print "Error creating output file."
        Return

    Define array names with inmate names
    Calculate numNames as size of names array divided by size of first element of names array
    Initialize currentEarpodID as 1000
    Seed random number generator using current time

    Loop from 0 to N - 1:
        Generate random index using rand() % numNames
        Get a random name from names array using the random index
        Create a Time object sleepTime
        Generate random sleep time using generateRandomTime function
        Generate random number p between 10 and 59
        Generate random musicID between 1 and 5
        Generate earpodID by incrementing currentEarpodID

        If currentEarpodID exceeds 10000:
            Print "Error: Maximum earpodID limit reached."
            Exit loop

        Write inmate record to output file:
            Write name, earpodID, sleepTime, p, and musicID to output file

    Close output file

	Define function generateDormRecords(int M, int numberofchannels):
    Open output file "Dorm_records.txt"
    If file cannot be opened:
        Print "Error creating output file."
        Return

    Initialize dormName as 'A'
    Seed random number generator using current time

    Loop from 0 to M - 1:
        Write "Dorm" + dormName + " " to output file
        Increment dormName for the next dorm

    Write newline character to output file

    Loop from 0 to numberofchannels - 1:
        Write channel numbers (starting from 10) to output file, separated by space

    Write newline character to output file

    Loop from 1 to 5:
        Write music ID numbers (starting from 1) to output file, separated by space

    Write newline character to output file

    Close output file

	Define function updateInmateRecords():
    Open input file "Inmate_records.txt"
    If file cannot be opened:
        Print "Error opening input file."
        Return

    Open output file "Inmate_records_updated.txt"
    If output file cannot be created:
        Print "Error creating output file."
        Close input file
        Return

    Initialize variables line, name, earpodID, hours, minutes, p, musicID
    Initialize Time object sleepTime

    Loop while reading lines from input file:
        Read line from input file
        Create stringstream ss from line
        Read name and earpodID from ss
        Loop 7 times:
            Read hours and minutes from ss
            Write hours and minutes to output file in HH:MM format
        Read p and musicID from ss
        Generate random sleep time using generateRandomTime function
        Write sleep time to output file in HH:MM format
        Write p and musicID to output file

    Close input and output files

	Define struct Record:
    Properties: name (string), EarpodID (int), MusicID (int), Dorm (int)

	Define struct MusicChannel:
    Properties: occupied (bool), dormIndex (int), earpodID (array of int), musicID (int)
    Constructor:
        Initialize occupied as false, dormIndex as -1, musicID as -1
        Initialize earpodID array with -1 for each element

    Initialize maximumEarpoIDs as 100

    Note: Assuming a maximum of 100 earpod IDs per channel

	Define main function:
    Initialize variables N, M, incrementation, peopleperdorm, numberofchannels
    Declare vectors DormName, ChannelIDrecord, MusicID
    Declare integer variables BackupChannels, Channelsize
    Declare integer pointer BackupEarpodID

    Initialize Channelsize as the size of ChannelIDrecord vector

    Initialize 2D vector ChannelID with dimensions Channelsize x peopleperdorm, initialized with 0

    Output "Enter number of inmates:"
    Input N
    Output "You have stated there are N inmates."

    Output "Enter number of Dorms:"
    Input M
    Output "You have kept M Dorms for inmates to stay."

    Output "Enter number of people per dorm:"
    Input peopleperdorm
    Output "You have set peopleperdorm people per dorm."

    Check if N is within dorm capacity:
        If yes, output "Thank you.. You can accommodate successfully."

    Check if N exceeds dorm capacity:
        If yes, output "Error: Number of inmates exceeds dorm capacity. Program terminated."
        Terminate the program with return 1

    Check if N exceeds dorm capacity with an extra dorm:
        If yes, prompt user to increase dorm capacity:
            Input 'y' for yes or any other character for no
            If input is 'y' or 'Y', increment peopleperdorm
            Otherwise, return 0 and exit program

    Output "Enter number of channels:"
    Input numberofchannels
    Output "You have set numberofchannels channels."

	Declare arrays names, times, Parray, musicIDarray, Musicstop, earpodIDarray of size N

	Declare char variable UserRandomtaken, fileCheck

	Output "Do you want to randomize the sleep time of inmates? Enter 'Y' or 'y' for yes, any other character for no:"
	Input UserRandomtaken
	Ignore newline character

	If UserRandomtaken is 'Y' or 'y':
    Output "Sleep time will be randomized"
    Call generateInmateRecords(N)

	Else:
    Output "Sleep time will not be randomized"
    Output "Please make sure that the file you are going to upload is named 'Inmate_records.txt'"
    Output "Is your file named 'Inmate_records.txt'? Enter 'Y' or 'y' for yes, any other character for no:"
    Input fileCheck
    Ignore newline character

    If fileCheck is not 'Y' and not 'y':
        Output "Please change the name to 'Inmate_records.txt' and re-run the program again"
        Terminate program with return 0

	Declare char variable UserDormtaken, fileCheck, s
	Declare integer variable check

	Output "Do you want to randomize the Dorms of inmates? Enter 'Y' or 'y' for yes, any other character for no:"
	Input UserDormtaken
	Ignore newline character

	If UserDormtaken is 'Y' or 'y':
    Output "Dorms will be randomized"
    Call generateDormRecords(M, numberofchannels)

	Else:
    Output "Dorms will not be randomized"
    Output "Please make sure that the file you are going to upload is named 'Dorm_records.txt'"
    Output "Is your file named 'Dorm_records.txt'? Enter 'Y' or 'y' for yes, any other character for no:"
    Input fileCheck
    Ignore newline character

    If fileCheck is not 'Y' and not 'y':
        Output "Please change the name to 'Dorm_records.txt' and run the program again"
        Terminate program with return 0

    Else:
        Open input file "Inmate_records.txt"
        If file cannot be opened:
            Output "Error opening file."
            Terminate program with return 0
        Else:
            Initialize check as 0
            Loop while reading lines from file:
                Increment check for each line read

            If check is not equal to N:
                Output "The file doesn't have N inputs."
                Output "Do you want to continue with check number of inputs? (Enter 'y' for yes, any other character for no)"
                Input s
                If s is 'y' or 'Y':
                    Set N as check
                    Output "Proceeding. Thank you. Please re-enter number again."
                    Proceed with re-entering N, M, and peopleperdorm values as in your previous code

                If N is less than or equal to M * peopleperdorm:
                    Output a new line

		Else if N exceeds M * (peopleperdorm + 1):
		    Output "Error: Number of inmates exceeds dorm capacity. Program terminated."
		    Terminate program with return 1

		Else if N is greater than M * peopleperdorm and less than or equal to M * (peopleperdorm + 1):
		    Output "We can still allocate inmates to dorms by increasing one dorm capacity. Do you want to continue? Enter 'y' for yes, any other character for no:"
		    Input y
		    If y is 'y' or 'Y':
		        Increment peopleperdorm by 1
		    Else:
		        Terminate program with return 0

		Else:
			Terminate program with return 0
			
	Output "How much incrementation do you want to take every cycle? Enter the value:"
	Input incrementation
	Ignore newline character

	Output "The time will increment every incrementation minutes."

	Open input file "Inmate_records.txt"
	If file is open:
    Initialize integer variable idx as 0
    Loop while reading lines from file and idx is less than N:
        Read line from file into myText
        Initialize stringstream ss with myText
        Declare string name
        Declare integer variables earpodID, hours, minutes, p, musicID

        Extract name and earpodID from ss and assign to names[idx] and earpodIDarray[idx]

        Initialize integer variables totalHours and totalMinutes as 0

        Loop 7 times for each day's sleep time:
            Extract hours and minutes from ss

            If hours is less than 0 or hours is greater than or equal to 24 or minutes is less than 0 or minutes is greater than or equal to 60:
                Output "Invalid time value: hours:minutes"
                Break the loop

            Increment totalHours by hours
            Increment totalMinutes by minutes

        Calculate averageHours as totalHours divided by 7
        Calculate averageMinutes as totalMinutes divided by 7

        Set times[idx] to averageHours and averageMinutes using times[idx].set(averageHours, averageMinutes)

        Extract p and musicID from ss and assign to Parray[idx] and musicIDarray[idx]

        Set Musicstop[idx] to times[idx] plus Parray[idx] minutes using Musicstop[idx].incrementMinutes(Parray[idx])

        Increment idx by 1

    Close input file

	Open input file "Dorm_records.txt"
	If file is open:
    Initialize string variable line
    If getline returns true (i.e., there is a line to read) from inFile into line:
        Initialize stringstream ss with line
        Initialize string variable dormName
        Loop while extracting dormName from ss:
            Append dormName to DormName vector

    Else:
        Output "Error: Empty file."
        Close inFile
        Return 1 to indicate error

    If getline returns true (i.e., there is a line to read) from inFile into line:
        Initialize stringstream ss with line
        Initialize integer variable channel
        Loop while extracting channel from ss:
            Append channel to ChannelIDrecord vector

    Else:
        Output "Error: Incomplete file."
        Close inFile
        Return 1 to indicate error

    If getline returns true (i.e., there is a line to read) from inFile into line:
        Initialize stringstream ss with line
        Initialize integer variable music
        Loop while extracting music from ss:
            Append music to MusicID vector

    Else:
        Output "Error: Incomplete file."
        Close inFile
        Return 1 to indicate error

    Close input File

	Output "There are currently N inmates in M dorms"
	Output "The Present Inmates average Sleep times are:"

	For each inmate i from 0 to N-1:
    Output names[i] left-aligned in a field of width 10
    Call times[i].printTime() to print the inmate's sleep time
    Output a newline

	Calculate Noofpeopleperdorm = N / M
	Calculate RemainingNoofpeopleperdorm = N % M

	Define Dorm as a 2D array of size M x Noofpeopleperdorm
	Define DormIDarray as an array of size equal to the number of elements in earpodIDarray, initialized with -1

	For each element in DormIDarray:
    Set the element to -1

	For each earpodID in earpodIDarray:
    For each dormitory j from 0 to MAX_DORMS-1:
        For each inmate k from 0 to MAX_INMATES_PER_DORM-1 in dormitory j:
            If Dorm[j][k] is equal to earpodID:
                Set DormIDarray[i] to j (the dormitory index)
                Break from the loop
        If DormIDarray[i] is not equal to -1:
            Break from the loop

	Define Records as an array of N Record structs
	Define ChannelControl as an array of size Channelsize of MusicChannel structs

	For each inmate i from 0 to N-1:
    Set Records[i].name to names[i]
    Set Records[i].EarpodID to earpodIDarray[i]
    Set Records[i].MusicID to musicIDarray[i]
    Set Records[i].Dorm to DormIDarray[i]

	Output "Time taken by each inmate to fall asleep are:" followed by a newline
	For each inmate i from 0 to N-1:
    Output names[i] left-aligned in a field of width 10
    Output ": " followed by Parray[i] and " minutes" then a newline

	Output a newline

	Output "Music for each inmate will Automatically stop at:" followed by a newline
	For each inmate i from 0 to N-1:
    Output names[i] left-aligned in a field of width 10
    Output ": "
    Call Musicstop[i].check() to adjust the time if needed
    Call Musicstop[i].printTime() to print the time
    Output a newline

	Define channels as an array of ChannelControl structs with size numberofchannels

	While currentTime is within range and not equal to 23:30:
    Output "Currently the time is: "
    Call currentTime.printTime()
    Output a newline

    Set musicStopped to true

    For each inmate i from 0 to N-1:
        If musicPlaying[i] is true and currentTime is greater than or equal to 	Musicstop[i]:
            Output "Music has stopped playing for " followed by names[i] 	left-aligned in a field of width 10, then " at "
            Call Musicstop[i].printTime()
            Output a newline
            Set musicPlaying[i] to false

            For each channel j from 0 to numberofchannels-1:
                If channels[j] is occupied and channels[j].earpodID has elements:
                    For each earpodID k in channels[j].earpodID:
                        If k is equal to Records[i].EarpodID:
                            Remove k from channels[j].earpodID
                            If channels[j].earpodID is empty:
                                Set channels[j].occupied to false
                                Output "Music Channel " followed by j + 10, " has become free."
                            Break from the loop

        If musicPlaying[i] is false:
            Set musicStopped to false

            If currentTime is greater than or equal to times[i] and times[i] is greater than or equal to PrevTime:
                Set sameDormMusicID to false
                For each channel j from 0 to numberofchannels-1:
                    If channels[j] is occupied and channels[j].dormIndex is equal to Records[i].Dorm and channels[j].musicID is equal to Records[i].MusicID:
                        Set sameDormMusicID to true
                        Set musicPlaying[i] to true
                        Add Records[i].EarpodID to channels[j].earpodID
                        Output "Multiple People in same Dorm with same MusicID Detected!"
                        Output "Music Channel " followed by j + 10, " has also been allocated for EarpodID ", Records[i].EarpodID, " with MusicID ", Records[i].MusicID
                        Break from the loop
                If sameDormMusicID is false:
                    For each channel j from 0 to numberofchannels-1:
                        If channels[j] is not occupied:
                            Set channels[j].occupied to true
                            Set channels[j].dormIndex to Records[i].Dorm
                            Set channels[j].musicID to Records[i].MusicID
                            Add Records[i].EarpodID to channels[j].earpodID
                            Output "Music Channel " followed by j + 10, " has been allocated for EarpodID ", Records[i].EarpodID, " with MusicID ", Records[i].MusicID
                            Set musicPlaying[i] to true
                            Break from the loop

        Else if musicPlaying[i] is true and Musicstop[i] is greater than or equal to currentTime:
            Output "Music is currently playing for " followed by names[i] left-aligned in a field of width 9
            Output a newline
            Set musicStopped to false

    If musicStopped is true:
        Output "Music is not being played for anyone right now"
        Output a newline

    Increment currentTime by incrementation minutes
    Increment PrevTime by incrementation minutes
    Output incrementation, " minutes have passed..."
    Output a newline

	Call updateInmateRecords()
	Output "Inmate records updated and saved to 'Inmate_records_updated.txt'."
	Return 0 to indicate successful program execution

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

   Vraj Chandrakant Patel , 
   Rishik Yalamanchili , 
    Lingampalli Venkata Subramanyam ,  
	Aaditya Thakkar.

## References

- https://www.geeksforgeeks.org/
- Resource center of DAIICT
