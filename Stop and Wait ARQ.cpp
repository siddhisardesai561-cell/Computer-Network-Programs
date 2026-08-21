#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    int total_frames;

    cout << "Enter the total number of frames to send: ";
    cin >> total_frames;

    if (total_frames <= 0)
    {
        cout << "Invalid number of frames." << endl;
        return 1;
    }

    srand(time(0));

    cout << "\n--- Starting Stop & Wait ARQ Simulation ---\n" << endl;

    int current_frame = 1;

    while (current_frame <= total_frames)
    {
        cout << "Sending Frame " << current_frame << "..." << endl;

        // 0 = Normal transmission
        // 1 = Frame lost
        // 2 = ACK lost
        int event = rand() % 3;

        if (event == 0)
        {
            // Normal transmission
            cout << "Frame " << current_frame
                 << " received successfully." << endl;

            cout << "ACK " << current_frame
                 << " received successfully!\n" << endl;

            current_frame++;
        }
        else if (event == 1)
        {
            // Frame lost
            cout << "Frame " << current_frame << " LOST!" << endl;

            cout << "Waiting for 5 seconds for ACK..." << endl;

            // Wait 5 seconds
            this_thread::sleep_for(chrono::seconds(5));

            cout << "Timeout! No ACK received." << endl;

            cout << "Retransmitting Frame "
                 << current_frame << "...\n" << endl;

            // Retransmission
            cout << "Frame " << current_frame
                 << " received successfully." << endl;

            cout << "ACK " << current_frame
                 << " received successfully!\n" << endl;

            current_frame++;
        }
        else
        {
            // ACK lost
            cout << "Frame " << current_frame
                 << " received successfully." << endl;

            cout << "Sending ACK " << current_frame << "..." << endl;

            cout << "ACK " << current_frame
                 << " LOST in transit!" << endl;

            cout << "Waiting for 5 seconds for ACK..." << endl;

            // Wait 5 seconds
            this_thread::sleep_for(chrono::seconds(5));

            cout << "Timeout! ACK not received." << endl;

            cout << "Retransmitting Frame "
                 << current_frame << "...\n" << endl;

            // Receiver detects duplicate
            cout << "Duplicate Frame " << current_frame
                 << " detected! Discarding duplicate frame." << endl;

            cout << "ACK " << current_frame
                 << " received successfully!\n" << endl;

            current_frame++;
        }
    }

    cout << "--- Transmission Completed Successfully ---" << endl;

    cout << "All " << total_frames
         << " frames sent and acknowledged." << endl;

    return 0;
}

//* Output :

Enter the total number of frames to send: 2

--- Starting Stop & Wait ARQ Simulation ---

Sending Frame 1...
Frame 1 LOST!
Waiting for 5 seconds for ACK...
Timeout! No ACK received.
Retransmitting Frame 1...

Frame 1 received successfully.
ACK 1 received successfully!

Sending Frame 2...
Frame 2 LOST!
Waiting for 5 seconds for ACK...
Timeout! No ACK received.
Retransmitting Frame 2...

Frame 2 received successfully.
ACK 2 received successfully!

--- Transmission Completed Successfully ---
All 2 frames sent and acknowledged.

*\\

