#include<stdio.h>
#include<stdlib.h>
#include"logger.h"


void logger(int logLevel,char* buffer)
{
	FILE* logFile;

	logFile = fopen("./logfile/logfile.log","a");


	if(logFile == NULL)
	{
    	printf("Error!");   
    	exit(1);             
	}


	switch (logLevel)
	{
		case LOG_LEVEL_INFO:
		{
			fprintf(logFile,"[INFO]: %s\n",buffer);
		}break;
		case LOG_LEVEL_WARNING:
		{
			fprintf(logFile,"[WARNING]: %s\n",buffer);
		}break;
		case LOG_LEVEL_ERROR:
		{
			fprintf(logFile,"[ERROR]: %s\n",buffer);
		}break;
		default:
		{
			printf("LOG LEVEL ERROR!");
			fprintf(logFile,"[NOTALOGLEVEL]: %s\n",buffer);
		}break;

	}
}
