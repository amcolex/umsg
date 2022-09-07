//
// Created by A.Pabouctsidis on 9/7/2022.
//

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <umsg_sensors.h>

// a simple pthread example
// compile with -lpthreads

// create the function to be executed as a thread
void *pub_thread(void *ptr)
{
    umsg_sensors_imu_t imu = {0};
    uint32_t counter = 0;
    while(1)
    {
        imu.temperature = counter;
        counter++;
        usleep(1e6);
    }
}

void *sub_thread(void *ptr)
{
    umsg_sensors_imu_t imu;

    umsg_queue_handle_t queue = umsg_sensors_imu_subscribe(1,1);
    while(1)
    {
        umsg_sensors_imu_receive(queue, &imu, 1000);
        printf("counter: %f", imu.temperature);
    }
}

int main(int argc, char **argv)
{
    // create the thread objs
    pthread_t pub_thread_handle;
    pthread_t sub_thread_handle;
    // start the threads
    pthread_create(&pub_thread_handle, NULL, pub_thread, NULL);
    pthread_create(&sub_thread_handle, NULL, sub_thread, NULL);

    pthread_join(pub_thread_handle,NULL);
    return 0;
}