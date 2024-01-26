#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

bool Validate_ID(string ID) // define the Validate_ID function (Keegan did this step)
{
    if (ID.length() != 6 || ID[0] != 'A') // make sure the user types in a capital A and five digits
    {
        return false;
    }

    for (int i = 1; i < ID.length(); i++) // make sure the user types in a number from 1 to 9
    {
        if (!isdigit(ID[i]) || ID[i] < '1' || ID[i] > '9')
        {
            return false;
        }
    }

    return true;
}
bool Unique_Question(int index, int *indices, int numberOfQuestions) // Define the Unique_Question function (Jada did this step)
{
    for (int i = 0; i < numberOfQuestions; i++)
    {
        if (indices[i] == index) // if questions are not randomized, return false
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string ID; // Step 1-Keegan
    int attempts = 0;
    bool validID = false;
    string firstName;
    string lastName;
    // Define variables
    std::cout << "Enter your first name: ";
    std::cin >> firstName;
    // ask the user for their first and last name
    std::cout << "Enter your last name: ";
    std::cin >> lastName;

    while (!validID) // Step 2-Keegan
    {
        std::cout << "Enter your ID (starts with A and followed by 5 digits): ";
        std::cin >> ID;
        validID = Validate_ID(ID); // call the validate_ID function
        // Making sure the user types in a valid id
        if (!validID)
        {
            attempts++;
            if (attempts == 3) // using an if statement to make sure the program exits after three attempts
            {
                std::cout << "You have exceeded the maximum number of attempts. Exiting program." << endl;
                return 0;
            }
            std::cout << "Invalid ID. Please enter a valid ID." << endl;
        }
    }

    // putting the questions and answers into an array Step 3-Jada
    string Q[100] = {"In computing, keyboards are used as input devices.",
                     "Operating systems are software systems that help make it more convenient to use computers and to manage the transitions between multiple jobs.",
                     "C++ is a superset of C; it \"spruces up\" the C language and provides capabilities for object oriented programming.",
                     "A computer is a device capable of performing computations and making logical decisions.",
                     "Most programs in C++ input data from stdin and output data from stdout.",
                     "The language understood by the microprocessor is called assembly language.",
                     "A machine cycle is the time it take the microprocessor to fetch and execute a complete instruction.",
                     "C, C++, and java are among the most powerful and most widely used assembly languages",
                     "Machine language is the \"natural language\" of a particular computer.",
                     "C++ has become widely used for writing software for computer networking and for distribution client/server applications.",
                     "Nintendo was founded after the year 1900.",
                     "Atomic bombs work by atomic fission.",
                     "CPU stands for central processing unit.",
                     "GPU stands for game processing unit.",
                     "The hubble telescope was named for Edwin Hubble.",
                     "Apple released the first iPhone in 2003.",
                     "Firefox and Chrome are examples of operating systems.",
                     "RAM stands for random-access memory.",
                     "Bill Gates was the only founder of microsoft.",
                     "Apple was the first company to produce a computer of any capacity.",
                     "It takes two memory locations (16 bits each) to store an address in the 8085 system",
                     "A compiler is a translation program that converts high-level instructions into a set of binary instructions (machine code) for execution.",
                     "The control bus and memories share a bidirectional bus in a typical microprocessor system.",
                     "The language understood by the microprocessor is called assembly language.",
                     "A machine cycle is the time it takes a microprocessor to fetch and execute a complete instruction.",
                     "An address bus is also called a unidirectional bus.",
                     "A coprocessor is a microprocessor designed with a limited instruction set optimized to perform arithmetic operations very quickly.",
                     "To keep the number of IC pins to a minimum, the 8085 uses a multiplexed bus.",
                     "Machine language is independent of the type of microprocessor in a computer system.",
                     "A mnemonic is an English-like instruction that is converted by an assembler into a machine code for use by a processor.",
                     "Social media actually goes back to some of the earliest Internet technologies and even predates the Internet.",
                     "E-mail is still the most popular online communication technology.",
                     "Pervasive computing refers to the fact that computer and communication devices allow one to access information anytime, anywhere.",
                     "The World Wide Web has been around for more than 30 years.",
                     "A client/server network consists of one client and several server computers.",
                     "Information is data that has been summarized or otherwise processed for use in decision-making.",
                     "Expansion slots provide a computer with additional secondary storage.",
                     "The focus of IT is to incorporate new, cutting-edge technologies into existing business processes.",
                     "Computers require programs, which are lists of specific instructions, in order to carry out their work.",
                     "People are a key ingredient in ensuring the success of information systems in a business environment.",
                     "A monitor displays information?",
                     "A SD card is an output device?",
                     "Microsoft office is a piece of software?",
                     "A firewall is a type of hardware?",
                     "A terabyte is equal to 1 million gigabytes?",
                     "Bluetooth allows your device to connect with another device",
                     "A processor accepts your commands for the computer?",
                     "Software that is free for trial is called shareware.?",
                     "CD stands for collective disk?",
                     "A pen drive is a storage device?",
                     "a microphone is used as an output device?",
                     "the CPU is referred as the stomache of the computer ?",
                     "a computer is a piece of hardware?",
                     "a processor accepts commands from your computer ?",
                     "the DVORAK keyboard is 20 times faster than your average QWERTY keyboard?",
                     "E-Mail was around before the world wide web?",
                     "8 bits = 1 byte?",
                     "HP, Microsoft, and Apple were all started in a garage?",
                     "the Firefox logo is actually a red panda?",
                     "a macbook battery is bulletproof?",
                     "4 bits = 1 nibble?",
                     "Microsoft office is a free software that comes pre-installed on every computer?",
                     "You can plug a USB 3.0 in both ways",
                     "Holding in the power button to turn off your computer corrupts data.",
                     "Electrostatic Discharge is when a computer component is electrocuted by static electricity from the handler.",
                     "A keyboard is the only input device that a computer can use",
                     "The \"home\" key takes you to your desktop",
                     "Each computer has a NIC or Network Interface Card",
                     "Each computer has a MAC Address that is used to locate it, like an IP Address",
                     "You're supposed to safely eject your flash drive before removing it to prevent data corruption",
                     "Mac and Windows are two different processing systems",
                     "Mac in made by Apple",
                     "Windows is made Microsoft",
                     "David Filo & Jeffry Yang developed google",
                     "Ray Tomlinson sent the first email",
                     "Google is the only internet search engine",
                     "Compact discs hold 1,000 minutes of music",
                     "The average power (in watts) used by a 20 to 25 inch color tv is 70 - 100 watts",
                     "the headquarters of intel is located in japan",
                     "Spam email is a myth",
                     "Hoverboards have been burtsing into flames because of faulty lithium batteries",
                     "Stereolithography is a type of 3D printing technoology",
                     "There are only 1 million mobile subscribers within the United States",
                     "Approximently 350 million snapchats are sent world wide every day",
                     "The first mouse was invented by Douglas Engelbart",
                     "Approximately 3 million cell phones are sold everyday",
                     "150 out of every 1000 computers are infected with spam",
                     "since 2008, DVD has out sold video games",
                     "HTC's dream was the first Android phone",
                     "the first ever cell phone weighed about 2 lbs",
                     "The first electronic computer ENIAC weighed more than 27 tons and took up 1800 square feet",
                     "90\% of the world�s currency is physical money.  The other 10% is on computers",
                     "\"Typewriter\" is the longest word that you can write using the letters only on one row of a keyboard",
                     "The first computer mouse was made of wood",
                     "There are less than 5000 new computer viruses released every month",
                     "50\% of Wikipedia vandalism is caught by a group of computer programs with more than 90% accuracy",
                     "If a computer was as powerful as a human brain, it would be able to execute 38,000-trillion operations a second",
                     "The password for nuclear missiles of the US was 00000000 for 8 years",
                     "70\% of virus writers are said to work under contract for the CIA",
                     "ASCII values are a series of 8 numbers between 1-3"};
    string A[100] = {"TRUE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "FALSE",
                     "FALSE",
                     "FALSE",
                     "FALSE",
                     "TRUE",
                     "FALSE",
                     "FALSE",
                     "TRUE",
                     "TRUE",
                     "FALSE",
                     "TRUE",
                     "FALSE",
                     "FALSE",
                     "TRUE",
                     "FALSE",
                     "FALSE",
                     "FALSE",
                     "TRUE",
                     "FALSE",
                     "FALSE",
                     "FALSE",
                     "TRUE",
                     "FALSE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "FALSE",
                     "TRUE",
                     "FALSE",
                     "FALSE",
                     "TRUE",
                     "FALSE",
                     "FALSE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "FALSE",
                     "TRUE",
                     "FALSE",
                     "FALSE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "FALSE",
                     "TRUE",
                     "FALSE",
                     "FALSE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "FALSE",
                     "FALSE",
                     "TRUE",
                     "TRUE",
                     "FALSE",
                     "FALSE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "FALSE",
                     "TRUE",
                     "FALSE",
                     "FALSE",
                     "TRUE",
                     "FALSE",
                     "FALSE",
                     "TRUE",
                     "TRUE",
                     "FALSE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "FALSE",
                     "FALSE",
                     "TRUE",
                     "TRUE",
                     "TRUE",
                     "FALSE",
                     "TRUE",
                     "TRUE",
                     "FALSE",
                     "FALSE",
                     "TRUE",
                     "TRUE",
                     "FALSE",
                     "FALSE"};

    // Step 4-Jada
    std::srand(time(NULL));    // initialize random seed
    time_t startTime, endTime; // creating start time and end time for the quiz report
    double weight;             // initializing weight
    int totalPoints = 0;       // initializing totalPoints to calculate the score in the end
    int numberOfQuestions;     // initialzing numberOfQuestions
    string questionsChosen;    // initializing the questions chosen to run the program with either 10 or 20 questions
    std::cout << "How many questions would you like in the quiz? (10 or 20): " << endl;
    std::cin >> questionsChosen; // extra credit (5 points)-Keegan & Jada

    if (questionsChosen == "10") // using if statements to run either a 10 or 20 question quiz
    {
        std::cout << "You have chosen to take the 10 question quiz. " << endl;
    }
    else if (questionsChosen == "20")
    {
        std::cout << "You have chosen to take the 20 question quiz. " << endl;
    }
    while (questionsChosen != "10" && questionsChosen != "20") // using a while loop to keep the program running until the user types in "10" or "20"
    {
        std::cout << "You must choose 10 or 20 questions to continue." << endl;
        std::cout << "How many questions would you like in the quiz? (10 or 20): " << endl;
        std::cin >> questionsChosen;
    }
    if (questionsChosen == "10") // initializing the weight of the questions in a 10 question quiz
    {
        numberOfQuestions = 10;
        weight = 1.0;
    }
    else if (questionsChosen == "20") // initializing the weight of the questions in a 20 question quiz
    {
        numberOfQuestions = 20;
        weight = 0.5;
    }
    int indices[numberOfQuestions];         // indices is an integer array to store the order of questions
    bool correctAnswers[numberOfQuestions]; // correctAnswers is a boolean array to store whether each answer is correct
    string answers[numberOfQuestions];      // answers stores the answer choices for each question
    string answer;
    int randomIndex = rand() % 100; // randomIndex will generate a random integer between 0 and 99 and store it
    std::srand(time(NULL));         // initialize random seed
    time(&startTime);               // start time on quiz
    for (int i = 0; i < numberOfQuestions; i++)
    {
        int index;
        do
        {
            index = rand() % 100;
        } while (!Unique_Question(index, indices, i)); // the Unique_Function is plugged in to make sure each question isnt repeated
        indices[i] = index;
    }

    for (int i = 0; i < numberOfQuestions; i++) // Step 5-Jada
    {

        do
        {
            cout << indices[i] << endl;
            std::cout << Q[indices[i]] << endl; // display each question

            std::cout << "Please enter true or false. " << endl;
            std::cin >> answer;                                                         // input the answer
            if (answer == "true" || answer == "TRUE" || answer == "T" || answer == "t") // use if statements to automatically capitalize t, T, TRUE, true
            {

                answer = "TRUE";
            }
            else if (answer == "false" || answer == "FALSE" || answer == "F" || answer == "f") // use if statements to automatically capitalize F, f, FALSE, or false
            {

                answer = "FALSE";
            }
            if (answer != "TRUE" && answer != "FALSE")
            {
                std::cout << "Please enter a valid answer. " << endl;
            }

        } while (answer != "FALSE" && answer != "TRUE"); // use if statement to make sure the user types in T, t, TRUE, true, F, f, FALSE, or false

        answers[i] = answer; // use this answer array to store each answer the user has entered

        if (answer == A[indices[i]]) // use if statements to calculate if the answer is correct
        {

            std::cout << "Correct! " << endl;
            correctAnswers[i] = true;
            totalPoints++; // add to totalPoints if answer is correct
        }
        else
        {
            std::cout << "Correct! " << endl;
            std::cout << "Incorrect. The answer is " << A[indices[i]] << endl;
            correctAnswers[i] = false;
        }

        time(&endTime); // end time

        int elapsedTime = difftime(endTime, startTime);
        if (elapsedTime > 600) // if user has taken over 10 minutes on quiz, exit program
        {
            std::cout << "Time's up! You have exceeded the time limit." << endl;
            return 0;
        }
    }
    // Step 6-Keegan

    // Calculating elapsed time
    int testTime = endTime - startTime;
    double maxPoints = numberOfQuestions * weight;
    double score = totalPoints * weight / maxPoints * 100; // use math to calculate score
    // Print out the quiz report
    std::cout << "\nQuiz Report for " << firstName << " " << lastName << endl;
    std::cout << "Score: " << fixed << setprecision(1) << score << "%" << endl;
    std::cout << "Elapsed Time: " << fixed << setprecision(1) << testTime << " seconds" << endl;
    std::cout << "Your answers: " << endl;
    for (int i = 0; i < numberOfQuestions; i++) // print out the answers the user entered
    {
        std::cout << i + 1 << ". " << answers[i] << endl; // use i + 1 to number questions correctly
    }
    std::cout << endl;
    std::cout << "Correct answers: " << endl; // print out correct answers
    for (int j = 0; j < numberOfQuestions; j++)
    {
        std::cout << j + 1 << ". " << A[indices[j]] << endl;
    }
    std::cout << endl;
    // Step 7-Keegan
    char choice;
    std::cout << "Enter Q to quit the program, or S to start a new quiz: ";
    std::cin >> choice; // allow user to choose whether they want to start a new quiz or quit

    while (choice != 'Q' && choice != 'S') // use a while loop to run the program over until the user enters "Q" or "S"
    {
        std::cout << "Invalid choice. Enter Q to quit the program, or S to start a new quiz: ";
        std::cin >> choice;
    }

    if (choice == 'Q')
    {
        std::cout << "Thank you for taking the quiz. Goodbye!" << endl;
        return 0; // exit the program if user wants to quit
    }
    while (choice == 'S')
    {                    // choice == 'S'
        system("clear"); // clear the screen
        main();          // return to main
        std::cout << "Enter Q to quit the program, or S to start a new quiz: ";
        std::cin >> choice; // start the quiz again
    }

    return 0; // terminate program
}
