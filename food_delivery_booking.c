#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int distance(char *a,char *b);
 void food_delivery(int);
 //combined orders of max 5 per Delivery Executive
     int booking_id=1,i=0;
     int DE1,DE2,DE3,DE4,DE5;
     int DE1_book,DE2_book,DE3_book,DE4_book,DE5_book;
     //Delivery charge of 5 for subsequent booking of every other order
  int delivery_charge[5];
    struct food
    {
        int customer_id;
        char restaurant[4];
        char destination_point[2];//from restaurant to destination point
        int time;
    }f[100];
    struct booking
    {
        int booking_id;
        int customer_id;
        char restaurant[4];
        char destination_point[2];
        int pick_time;
        int delivery_time;
        int delivery_charge;
    }b[4][100];

void booking(struct booking *b,struct food f,int no,int count)
{
b->customer_id=f.customer_id;
b->booking_id=booking_id++;
strcpy(b->restaurant,f.restaurant);
strcpy(b->destination_point,f.destination_point);
b->pick_time=f.time;
b->delivery_time =distance(f.restaurant,f.destination_point)+f.time;
if(b->delivery_time>12)
{
 b->delivery_time-=12;
}

if(count==1)
{
	b->delivery_charge=50;
}
else
{
    //if the delivery is to the same destination,then delivery charge gets added up with rs.5 on every order
	b->delivery_charge=50+5*(count-1);
}
delivery_charge[no]+=b->delivery_charge;
}

int distance(char *a,char *b)
{//starting point and destinations are taken as alphabets
 char start=a[0];
 char stop=b[0];
 return (abs(start-stop));
}
void food_delivery(int DE)
{
 printf("\nOutput \n ");
 printf("\nBooking ID %d\n",DE);
 printf("\nAvailable Executives :");
 printf("\nExecutive       Delivery Charge Earned \n");
 printf("\n   DE1                   %d",delivery_charge[1]);
 printf("\n   DE2                   %d",delivery_charge[1]);
 printf("\n   DE3                   %d",delivery_charge[2]);
 printf("\n   DE4                   %d",delivery_charge[3]);
 printf("\n   DE5                   %d",delivery_charge[4]);
 printf("\nAllotted Delivery  Executive:DE%d",b[0][i].customer_id);
}
void display()//displaying the delivery history
{
if(DE1_book>0)
 {
     printf("\nDelivery history\n");
     printf("\noutput\n");
 	printf("\nDE 1 \n total Earning= %d\n",delivery_charge[0]);
     printf("\n TRIP   EXECUTIVE  RESTAURANT  DESTINATION_POINT  PICKUP_TIME  DELIVERY_TIME  DELIVERY_CHARGE\n");
  for(int i=0;i<DE1_book;i++)
  {
   printf("\n%d           %d         %s              %s               %d           %d            %d\n",b[0][i].booking_id,b[0][i].customer_id,b[0][i].restaurant,b[0][i].destination_point,b[0][i].pick_time,b[0][i].delivery_time,b[0][i].delivery_charge);
  }
 }
 if(DE2_book>0)
 {
  printf("\nDE2 \n total Earning= %d\n",delivery_charge[1]);
     printf("\n TRIP   EXECUTIVE  RESTAURANT  DESTINATION_POINT  PICKUP_TIME  DELIVERY_TIME  DELIVERY_CHARGE\n");
  for(int i=0;i<DE2_book;i++)
  {
   printf("\n%d           %d           %s             %s                %d             %d                %d\n",b[1][i].booking_id,b[1][i].customer_id,b[1][i].restaurant,b[1][i].destination_point,b[1][i].pick_time,b[1][i].delivery_time,b[1][i].delivery_charge);
  }
 }if(DE3_book>0)
 {
  printf("\nDE 3 \n total Earning= %d\n",delivery_charge[2]);
     printf("\n TRIP   EXECUTIVE  RESTAURANT  DESTINATION_POINT  PICKUP_TIME  DELIVERY_TIME  DELIVERY_CHARGE\n");
  for(int i=0;i<DE3_book;i++)
  {
   printf("\n%d          %d          %s              %s                %d              %d                 %d\n",b[2][i].booking_id,b[2][i].customer_id,b[2][i].restaurant,b[2][i].destination_point,b[2][i].pick_time,b[2][i].delivery_time,b[2][i].delivery_charge);
  }
 }if(DE4_book>0)
 {
  printf("\nDE4 \n total Earning= %d\n",delivery_charge[3]);
     printf("\n TRIP   EXECUTIVE  RESTAURANT  DESTINATION_POINT  PICKUP_TIME  DELIVERY_TIME  DELIVERY_CHARGE\n");
  for(int i=0;i<DE4_book;i++)
  {
   printf("\n%d            %d             %s            %s              %d            %d             %d\n",b[3][i].booking_id,b[3][i].customer_id,b[3][i].restaurant,b[3][i].destination_point,b[3][i].pick_time,b[3][i].delivery_time,b[3][i].delivery_charge);
  }
}
  if(DE5_book>0)
 {
  printf("\nDE5 \n total Earning= %d\n",delivery_charge[4]);
     printf("\n TRIP   EXECUTIVE  RESTAURANT  DESTINATION_POINT  PICKUP_TIME  DELIVERY_TIME  DELIVERY_CHARGE\n");
  for(int i=0;i<DE5_book;i++)
  {
   printf("\n%d             %d             %s            %s            %d             %d           %d\n",b[4][i].booking_id,b[4][i].customer_id,b[4][i].restaurant,b[4][i].destination_point,b[4][i].pick_time,b[4][i].delivery_time,b[4][i].delivery_charge);
  }
  }
 }
int main()
{

    while(1)
    {
        int user_choice,count,i;
        
        printf("\n...................Food Delivery Booking..............................................\n");
        printf("\n 1.Booking  2.Details 3.exit \n");
        printf("Enter Choice:");
        scanf("%d",&user_choice);
        if(user_choice==1)
        {
            printf("\nNo. of bookings :");
            scanf("%d",&count);
            for(i=0;i<count;i++)
            {
                printf("\nInput %d:\n",i+1);
                printf("\nCustomer Id :");
                scanf("%d",&f[i].customer_id);
                printf("\nRestaurant :");
                scanf("%s",f[i].restaurant);
                printf("\nDestination point :");
                scanf("%s",f[i].destination_point);
                printf("\nTime :");
                scanf("%d",&f[i].time);
                if(DE1==0)
                {
                booking(&b[0][DE1_book++],f[i],0,count);
                DE1=distance(f[i].restaurant,f[i].destination_point);
                food_delivery(1);
                }
                else if(DE2==0)
                {
                booking(&b[1][DE2_book++],f[i],1,count);
                DE2=distance(f[i].restaurant,f[i].destination_point);
                food_delivery(2);
                }
                else if(DE3==0)
                {
                booking(&b[2][DE3_book++],f[i],2,count);
                DE3=distance(f[i].restaurant,f[i].destination_point);
                food_delivery(3);
                }
                else if(DE4==0)
                {
                booking(&b[3][DE4_book++],f[i],3,count);
                DE4=distance(f[i].restaurant,f[i].destination_point);
                food_delivery(4);
                }
                else if(DE5==0)
                {
                booking(&b[4][DE5_book++],f[i],4,count);
                DE5=distance(f[i].restaurant,f[i].destination_point);
                food_delivery(5);
                }
                else
                {
                 printf("ALL Executives Are Busy.. Please Try after Some time");
                }
            }
       }
        else if(user_choice==2)
        {
            display();
        }
        else
        {
            return 10+delivery_charge[i];
        }
}
}
