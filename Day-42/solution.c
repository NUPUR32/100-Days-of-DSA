#include <stdio.h>
#include <stdlib.h>

int allDone(int freq[]) {
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0)
            return 0;
    }
    return 1;
}

int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};
    int cooldown[26] = {0};

    // Count frequency of each task
    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    int time = 0;

    while (!allDone(freq)) {

        int taskIndex = -1;
        int maxFreq = 0;

        // Find task with highest frequency
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0 &&
                cooldown[i] == 0 &&
                freq[i] > maxFreq) {

                maxFreq = freq[i];
                taskIndex = i;
            }
        }

        // Execute task
        if (taskIndex != -1) {
            freq[taskIndex]--;
            cooldown[taskIndex] = n + 1;
        }

        // Decrease cooldown
        for (int i = 0; i < 26; i++) {
            if (cooldown[i] > 0)
                cooldown[i]--;
        }

        time++;
    }

    return time;
}

int main() {
    char tasks[] = {'A', 'A', 'A', 'B', 'B', 'B'};
    int tasksSize = sizeof(tasks) / sizeof(tasks[0]);
    int n = 2;

    int result = leastInterval(tasks, tasksSize, n);

    printf("Minimum intervals: %d\n", result);

    return 0;
}