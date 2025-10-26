#include"jlmake.h"
void selfmake(struct BASIC basic,graphitem*graph)
{
	int i,j,m=0,n=0,l,k;
	char *pp=malloc(1000);
	char *s=malloc(1000);
	char *abc=malloc(1000);
	FILE *fp;
	if((fp=fopen(basic.txpp,"r"))==NULL)
	{
		prt_hz24d(100,100,"读取文件错误",0,"HZK\\Hzk24k");
	}
	for(i=0;i<1500;i++)
	{
		abc[i]=fgetc(fp); 
		if(abc[i]==' '&&abc[i-1]==' ')
		{
			break;
		}
		
	}
	abc[i-1]='\0';

   fclose (fp);

	for (i = 0;i < 20;i++)
	{
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	
		if(graph[i].shape==6)
		{
			strcpy(pp,graph[i].title );
			strcat(pp,"\:");
			// putput3(graph[i].x0,graph[i].y0,1,1,pp,0,graph[i].x1,graph[i].y1,graph[i].color);
			l=strlen(pp);
	      	for(k=0;k<strlen(abc);k++)
	      	{
	      		strcpy(s,abc+k);
	      		strcpy(s+l,"\0");
	      		if(strcmp(s,pp)==0)
	      		{
	      			break;
				}
			}
		strcpy(s,abc+k);
		for(j=strlen(pp);j<strlen(s);j++)
		{
		     strcpy(pp,s+j);
		     strcpy(pp+5,"\0");
		     if(strcmp(pp,"educa")==0||
	            strcmp(pp,"honor")==0||
	            strcmp(pp,"objec")==0||
	  		    strcmp(pp,"other")==0||
	  			strcmp(pp,"jobsk")==0||
	   			strcmp(pp,"evalu")==0
				)
	   		 	{
	    			for(m=0,n=0;m<7;m++)
					{
						if (s[j+5+m]==':')
		    			{
							n=1;
		    				break;
		  			  	}
					}
			if(n==1)
	   		break;
    			}
   		}
    	strcpy(pp,s+l);
    	strcpy(pp+j-l,"\0");
        putput3(graph[i].x0,graph[i].y0,1,1,pp,0,graph[i].x1,graph[i].y1,graph[i].color);
	   } 
   }
	free(abc);
    free(s);
    free(pp);
}

