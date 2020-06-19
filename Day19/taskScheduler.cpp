public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int task[26];                 // Task array to store the count of each task,
        memset(task, 0, sizeof task); // initialised to 0.
        
        for(char i : tasks)  // For-each loop to iterate over tasks and update the task 
            task[i - 'A']++; // frequencies simultaneously.
        
        sort(task, task + 26);  // Sorting the frequencies in ascending order so that the 
                                // highest frequencies come to last. Name of the tasks do
                                // not matter to us, we only need frequencies.
        
        int max_v = task[25] - 1; // Max value of frequency of tasks.
        int idle = max_v * n;     // Maximum number of idle slots we can have.
        
        for(int i = 24; i >= 0; i--){           // Iterating over frequencies, except the
                                                // maximum freq. we obtained earlier
            
            idle = idle - min(max_v, task[i]);  // Updating the idle slots because as we do
                                                // some more tasks, the slots would be filled
                                                // and no. of idle slots will reduce.
        }                                       
                                                            
        if(idle < 0)    // If all idle slots are filled or there are even more tasks than no.
            idle = 0;   // of idle slots, our answer would be no. of tasks in total i.e. 
                        // CPU would be busy the entire time, and cooldown time between all 
                        // tasks would be satisfied.
        
                                    // Total cycles needed. If there are idle slots present
        return tasks.size() + idle; // we add them to total tasks.
    }