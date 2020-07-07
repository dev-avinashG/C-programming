#include<stdio.h>

#include<string.h>

#include<stdlib.h>

int studcount = 12;
int room[3][10] = {{0},{0},{0}};

//Declaring structure to save student details
struct stud
{
        char name[30];
        long int userid;
        char gender;
        char roll[5];
        double mobnum;
        char email[30];
        struct room
        {
                int hostel;
                int roomnum;
        }
        r;
        float fee;
        char complain[500];

}
s[31];

//Declaring functions
void regdata();
void displayerrorpwd();
void displayerrorchoice();
void displaychoice();
void displayadminchoice();
void displayregstudentchoice();
void displaychoose();
int searchid();
void checkpwd(int j);
void addstud();
void deletestud(int);
void displaystud(int);
void displayhostel();
void displayemptyroom();
int searchroom(int, int);
int revstring(char[]);
void changemobile(int);
void changemail(int);
void addcomplain(int);
void printline();
void printstar();
int checkadminpwd(char[], char[]);

//Main function
int main()
{
	
        regdata();
        int a, b;
        char pwd[9] = {'N','i','t','k','2','0','2','0','\0'}, ipwd[9];
        printf("--:WELCOME TO NITK HOSTEL MANAGEMENT SYSTEM:--\n\n");
        printline();
        printf("----------:Instructions:----------");
        printstar();
        printf("-->There are 3 hostels and each hostel has 10 rooms.\n-->Hostel-3 is For FEMALE.\n-->Hostel-1 and Hostel-2 is for Boys.\n-->First 4 rooms of each hostels is pre-occupied with some students.");
        printstar();
        printline();
        printf("NOTE:--> Default admin Password is : Nitk2020");
        printline();
        pgstart:
                printf("Please Choose:\n1. HOSTEL ADMIN\n2. STUDENT\n3. EXIT PROGRAM\n");
        nitklog:
                printline();
                scanf("%d", & a);
        switch (a)

        {
        case 1:
                {
                        printf("Enter password:");
                        adminlogin: scanf(" %8s", ipwd);
                        printline();
                        if (checkadminpwd(pwd, ipwd) == 1)
                            {
                                printf("\nLogin Successful.....\n");
                                adminrepeat:
                                            displaychoose();
                                            displayadminchoice();
                                            int achoice;
                                adminchoice:
                                            printline();
                                            scanf("%d", & achoice);
                                switch (achoice)
                                {
                                case 1:
                                        {
                                                addstud();
                                                printf("\nAdded Successfully\n");
                                                goto adminrepeat;
                                        }
                                        break;
                                case 2:
                                        {
                                                int p,q;
									            p= searchid();
									            displaystud(p);
									            printf("Enter 1 to confirm delete else 2 to go back.\n");
						                        re_delete:
									                      scanf("%d",&q);
                                                if(q==1)
								                {
									              deletestud(p);
									              goto adminrepeat;
								                }
							                    else if( q==2)
                                                {
									            goto adminrepeat;
								                }
							                    else
								                {
                                                displayerrorchoice();
								                goto re_delete;
									            }
                                        }
                                        break;
                                case 3:
                                        {
                                                displayhostel();
                                                goto adminrepeat;

                                        }
                                        break;
                                case 4:
                                        {
                                                int sid;
                                                sid = searchid();
                                                displaystud(sid);
                                                goto adminrepeat;
                                        }
                                        break;
                                case 5:
                                        {
                                                int ho,
                                                ro,
                                                x;

                                                r_empty: printf("\nEnter :--\nHostel no.: ");
                                                h_error: scanf("%d", & ho);
                                                if (ho < 1 || ho > 3)
                                                {
                                                        printf("\nInvalid Hostel no.!Please Retry...\n");
                                                        goto h_error;
                                                }
                                                printf("\nRoom no.: ");
                                                r_error: scanf("%d", & ro);
                                                if (ro < 1 || ro > 10)
                                                {
                                                        printf("\nInvalid Room no.!Please Retry...\n");
                                                        goto r_error;
                                                }
                                                if (room[ho - 1][ro - 1] != 1)
                                                {
                                                        printf("\nRoom is EMPTY! Please Retry with different Room no.:-\n");
                                                        goto r_empty;

                                                }

                                                x = searchroom(ho, ro);
                                                displaystud(x);
                                                goto adminrepeat;
                                        }
                                        break;
                                case 6:
                                        {

                                                displayemptyroom();
                                                goto adminrepeat;

                                        }
                                        break;
                                case 7:
                                        {
                                                printf("\nLOGOUT SUCCESS...\n");
                                                goto pgstart;
                                        }
                                        break;
                                default:
                                        {
                                                displayerrorchoice();
                                                goto adminchoice;
                                        }
                                        break;
                                }
                        }
                        else
                        {
                                displayerrorpwd();
                                goto adminlogin;
                        }
                }

                break;
        case 2:
                {
                        printf("Choose:\n1.) Registered\n2.) New User\n");
                        stulogin:
                                 printline();
                                 scanf("%d", & b);
                        switch (b)
                        {

                        case 1:
                                {
                                        printstar();
                                        printf("NOTE: User id is your Registration no. and password is your Last 3 digit\n Ex: for 191776MN234 : user_id/Reg. no.=191776 ,password=234\n");
                                        printline();
                                        long int tempwd;
                                        int j;
                                        j = searchid();
                                        printf("\nEnter password:");
                                        checkpwd(j);

                                        stustart:
                                                  displaychoose();
                                                  displayregstudentchoice();
                                                  int choice;
                                        re_choice:
                                                  printline();
                                                  scanf("%d", & choice);
                                        switch (choice)
                                        {

                                        case 1:
                                                {
                                                        displaystud(j);
                                                        goto stustart;

                                                }
                                                break;

                                        case 2:
                                                {
                                                        changemobile(j);
                                                        goto stustart;

                                                }
                                                break;

                                        case 3:
                                                {
                                                        changemail(j);
                                                        goto stustart;
                                                }
                                                break;

                                        case 4:
                                                {
                                                        addcomplain(j);
                                                        goto stustart;
                                                }
                                                break;

                                        case 5:
                                                {
                                                        printf("\nLOGOUT SUCCESS...\n");
                                                        goto pgstart;

                                                }
                                                break;

                                        default:
                                                {
                                                        displayerrorchoice();
                                                        goto re_choice;

                                                }
                                                break;
                                        }

                                }
                                break;

                        case 2:
                               printf("\nNOTE---> \n1.) There are 3 Hostels 1 to 3 .\n");
			       printf("2.) Hostel-1 and Hostel-2 is for Boys and Hostel-3 is for Girls.\n");
			       printf("3.) Fee Structure: Rs. 6,000/- for a semester.");
			       printline();
                               {
                                        addstud();
                                        goto pgstart;
                               }

                                break;

                        default:
                                {
                                        printf("\nPlease Choose a Valid Choice!\n");
                                        goto stulogin;
                                }
                                break;
                        }
                }

                break;
        case 3:
                {
                        return 0;
                }
                break;
        default:
                {
                        printf("\nChoose a Valid choice:\n");
                        goto nitklog;
                }
                break;

        }

}

void displaychoose()
{
        printf("\nChoose an Option:\n");
}

void displayadminchoice()//Function to display choices for admin
{
        printf("1.) Add a student\n2.) Remove student\n3.) Display  student data by hostel\n4.) Search by Registration no.\n5.) search by room_address\n6.) Display empty room\n7.) LogOut\n");

}

void displayregstudentchoice() //Function to display choices for registered students
{
        printf("1.) Display your Data\n2.) Change Mobile no.\n3.) Change Email_id\n4.) Add complaints\n5.)  Log out\n");
}
void displayerrorpwd()
{
        printf("\nWrong Password! Please Try again...\n");
}
void displayerrorchoice()
{
        printf("\nInvalid choice! please re-enter:\n");
}

int searchid()//Function to search and display student data using user_id
{
        long int k;
        printf("\nEnter Reg. no. / User id:");
        usrid:
                scanf("%ld", & k);
        int j;
        for (j = 0; j < 30; j++)
        {
                if (s[j].userid == k)
                        break;
        }
        if (j < 30)
        {
                return j;
        }
        else
        {
                printf("\nInvalid user id! please retry...\n");
                goto usrid;
        }
}

void checkpwd(int j)//Function to check student login password
{
        int tempwd;

        repwd:
                scanf("%d", & tempwd);
        if (revstring(s[j].roll) == tempwd)
        {
                printf("\nLOGIN SUCCEESS...");
                printline();
        }
        else
        {
                displayerrorpwd();
                goto repwd;
        }
}

void addstud() //Function to add new student
{
        studcount++;
        int k = studcount - 1;
        printf("Enter student's Details ");
        printstar();
        printf("\nName\t:");
        scanf(" %[^\n]s ", s[k].name);
        printf("\nReg. no.(This will be your userid): ");
        scanf(" %ld", & s[k].userid);
        printf("\nGender(M/F)\t:");
        scanf(" %c", & s[k].gender);
        printf("\nRoll no.(Ex-CV888)\t: ");
        scanf(" %5s", s[k].roll);
        printf("\nMobile no.\t: ");
        scanf(" %lf", & s[k].mobnum);
        printf("\nEmail\t: ");
        scanf(" %[^\n]s", s[k].email);
        printf("\nNote:--> Hostel-1 and Hostel-2 are for MALE and only Hostel-3 for FEMALE.");
        hostel_error:
                printline();
        printf("\nHostel no.: ");

        scanf(" %d", & s[k].r.hostel);
        printf("\nEnter room no.: ");
        scanf(" %d", & s[k].r.roomnum);
        if (room[s[k].r.hostel - 1][s[k].r.roomnum - 1] == 1)
        {
                printline();
                printf("\nRoom is already alotted! Please choose different room.\n Here is list of empty rooms...");
                displayemptyroom();
                printline();
                goto hostel_error;
        }

        if ((s[k].gender == 'M' || s[k].gender == 'm') && (s[k].r.hostel == 1 || s[k].r.hostel == 2))

        {
                room[s[k].r.hostel - 1][s[k].r.roomnum - 1] = 1;
                printf("\nREGISTERED SUCCESSFULLY\n");

        }
         else if ((s[k].gender == 'F' || s[k].gender == 'f') && s[k].r.hostel == 3)
        {
                room[s[k].r.hostel - 1][s[k].r.roomnum - 1] = 1;
                printf("\nREGISTERED SUCCESSFULLY\n");

        }
         else
        {
                printf("Invalid choice! Please choose correct hostel and room no.\n");
                goto hostel_error;

        }

        s[k].fee = 0;
        printline();

}

void displaystud(int l) //Function to display details of all students
{
        printf("\nName           : %s", s[l].name);
        printf("\nReg. no.       : %ld", s[l].userid);
        printf("\nGender         : %c", s[l].gender);
        printf("\nRoll no.       : %s", s[l].roll);
        printf("\nMob. no.       : %.lf", s[l].mobnum);
        printf("\nemail          : %s", s[l].email);
        printf("\nHostel         : %d\nroom no.       : %d", s[l].r.hostel, s[l].r.roomnum);
        printf("\nFee_Due        : %.2f", s[l].fee);
        printf("\nHostel_complain: %s\n", s[l].complain);
        printline();

}

int revstring(char c[6]) //Function to extract last 3 digits from student's roll no
{
        char d[4];
        int m, n;
        for (m = 0; m < 3; m++)
        {
                d[m] = c[m + 2];
        }
        d[3] = '\0';
        n = atoi(d);
        return n;
}
void displayhostel() //Function to display student details according to hostel no and room no
{
        int h, r, p;
        for (h = 0; h < 3; h++)
        {
                printf("\nHOSTEL---: %d\n__________\n\n", h + 1);

                for (r = 0; r < 10; r++)
                {
                        if (room[h][r] == 1)
                        {
                                printf("\n\t\tROOM NO.:%d\n________\n", r + 1);
                                p = searchroom(h + 1, r + 1);
                                displaystud(p);
                        }

                }

        }
}

void displayemptyroom() //Function to display empty rooms
{
        int i, j;
        for (i = 0; i < 3; i++)
        {
                printf("\n-------HOSTEL-------%d\n***********\n--Empty Rooms--:\n", i + 1);
                for (j = 0; j < 10; j++)
                {
                        if (room[i][j] != 1)
                        {
                                printf("%d\t", j + 1);
                        }
                }
                printf("\n");
        }
}

int searchroom(int h, int r) //Function to display student details of a particular room
{
        int x;

        for (x = 0; x < 30; x++)
        {
                if ((s[x].r.roomnum == r) && (s[x].r.hostel == h))
                {
                        printf("\n----:FOUND!:---\n");

                        break;
                }
        }
        return x;
}

void changemobile(int m) //Function to update mobile number
{
        printf("\nEnter New Mobile: ");
        scanf("%lf", & s[m].mobnum);
        printf("\nMobile no. Changed SUCCESSFFULLY...\n");
        printline();

}

void changemail(int m) //Function to update email
{
        printf("\nEnter new email: ");
        scanf(" %[^\n]s", s[m].email);
        printf("\nEmail Changed SUCCESSFULLY...\n");
        printline();
}

void addcomplain(int m) //Function to add complain
{
        printf("\nEnter a New Complain : ");
        scanf(" %[^\n]s", s[m].complain);
        printf("\n\nComplain Registration SUCCESSFFUL...\n");
        printline();
}

void printline()
{
        printf("\n_________________________________________________\n");
}

void printstar()
{
        printf("\n*************************************************\n");
}
int checkadminpwd(char pwd[8], char ipwd[8]) //Function to check admin login password
{
        int n;
        for (n = 0; n < 8; n++)
        {
                if (pwd[n] != ipwd[n])
                {

                        break;
                }
        }
        if (n == 8)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

void regdata() //Function to store details of registered students
{
        strcpy(s[0].name, "Ishan M B");
        s[0].userid = 191829;
        s[0].gender = 'M';
        strcpy(s[0].roll, "CV122");
        s[0].mobnum = 9898989898;
        strcpy(s[0].email, "ishaanmb.191cv122@nitk.edu.in");
        s[0].r.hostel = 1;
        s[0].r.roomnum = 1;
        room[0][0] = 1;
        s[0].fee = 33650;
        strcpy(s[0].complain, "One light is not working in my room");

        strcpy(s[1].name, "KEVAL VAGHAMSHI");
        s[1].userid = 191667;
        s[1].gender = 'M';
        strcpy(s[1].roll, "CV129");
        s[1].mobnum = 8080808080;
        strcpy(s[1].email, "keval.191cv129@nitk.edu.in");
        s[1].r.hostel = 1;
        s[1].r.roomnum = 2;
        room[0][1] = 1;
        s[1].fee = 33650;
        strcpy(s[1].complain, "One light is not working in my room");

        strcpy(s[2].name, "Rahul Marval");
        s[2].userid = 191823;
        s[2].gender = 'M';
        strcpy(s[2].roll, "CV141");
        s[2].mobnum = 7878787878;
        strcpy(s[2].email, "rahulmarval917@gmail.com");
        s[2].r.hostel = 1;
        s[2].r.roomnum = 3;
        room[0][2] = 1;
        s[2].fee = 33650;
        strcpy(s[2].complain, "Fan got fallen on ground");

        strcpy(s[3].name, "Tarun Vishnoi");
        s[3].userid = 191648;
        s[3].gender = 'M';
        strcpy(s[3].roll, "CV152");
        s[3].mobnum = 8888888888;
        strcpy(s[3].email, "tarunvishnoi.191cv152@nitk.edu.in");
        s[3].r.hostel = 1;
        s[3].r.roomnum = 4;
        room[0][3] = 1;
        s[3].fee = 33650;
        strcpy(s[3].complain, "Both light is not working in my room");

        strcpy(s[4].name, "Wilson Furtado");
        s[4].userid = 191885;
        s[4].gender = 'M';
        strcpy(s[4].roll, "CV155");
        s[4].mobnum = 7575757575;
        strcpy(s[4].email, "wilson.191cv155@nitk.edu.in");
        s[4].r.hostel = 2;
        s[4].r.roomnum = 1;
        room[1][0] = 1;
        s[4].fee = 33650;
        strcpy(s[4].complain, "fan is not working");

        strcpy(s[5].name, "Y Prathap");
        s[5].userid = 191914;
        s[5].gender = 'M';
        strcpy(s[5].roll, "CV156");
        s[5].mobnum = 8585858585;
        strcpy(s[5].email, "yprathap.191cv156@nitk.edu.in");
        s[5].r.hostel = 2;
        s[5].r.roomnum = 2;
        room[1][1] = 1;
        s[5].fee = 33650;
        strcpy(s[5].complain, "     ");

        strcpy(s[6].name, "Afnan Khan");
        s[6].userid = 191929;
        s[6].gender = 'M';
        strcpy(s[6].roll, "CV202");
        s[6].mobnum = 6565656565;
        strcpy(s[6].email, "afnan.191cv202@nitk.edu.in");
        s[6].r.hostel = 2;
        s[6].r.roomnum = 3;
        room[1][2] = 1;
        s[6].fee = 33650;
        strcpy(s[6].complain, "     ");

        strcpy(s[7].name, "Aman Jain");
        s[7].userid = 191907;
        s[7].gender = 'M';
        strcpy(s[7].roll, "CV203");
        s[7].mobnum = 9595959595;
        strcpy(s[7].email, "amanjain.191cv203@nitk.edu");
        s[7].r.hostel = 2;
        s[7].r.roomnum = 4;
        room[1][3] = 1;
        s[7].fee = 33650;
        strcpy(s[7].complain, "     ");

        strcpy(s[8].name, "Huda M");
        s[8].userid = 191924;
        s[8].gender = 'F';
        strcpy(s[8].roll, "CV221");
        s[8].mobnum = 7070707070;
        strcpy(s[8].email, "Hudamannath.191CV221@nitk. edu.in");
        s[8].r.hostel = 3;
        s[8].r.roomnum = 1;
        room[2][0] = 1;
        s[8].fee = 33650;
        strcpy(s[8].complain, "my fan is not working");

        strcpy(s[9].name, "Jahanvi chaudhary");
        s[9].userid = 191901;
        s[9].gender = 'F';
        strcpy(s[9].roll, "MN015");
        s[9].mobnum = 9090909090;
        strcpy(s[9].email, "jahanvichaudhary2001@gmail.com");
        s[9].r.hostel = 3;
        s[9].r.roomnum = 2;
        room[2][1] = 1;
        s[9].fee = 33650;
        strcpy(s[9].complain, " ");

        strcpy(s[10].name, "B Namratha Kamath");
        s[10].userid = 181827;
        s[10].gender = 'F';
        strcpy(s[10].roll, "MN005");
        s[10].mobnum = 6060606060;
        strcpy(s[10].email, "bnamrathakamath25@gmail.co m");
        s[10].r.hostel = 3;
        s[10].r.roomnum = 3;
        room[2][2] = 1;
        s[10].fee = 33650;
        strcpy(s[10].complain, " too much sound near my room");

        strcpy(s[11].name, "Tejal Anant Narvekar");
        s[11].userid = 191845;
        s[11].gender = 'F';
        strcpy(s[11].roll, "CV250");
        s[11].mobnum = 8989898989;
        strcpy(s[11].email, "bnamrathakamath25@gmail.co m");
        s[11].r.hostel = 3;
        s[11].r.roomnum = 4;
        room[2][3] = 1;
        s[11].fee = 33650;
        strcpy(s[11].complain, " ");

}
void deletestud( int p)
{	int z;

	room[s[p].r.hostel-1][s[p].r.roomnum-1]=0;

	for(z=p;z<31;z++)
	{
		s[p]= s[p+1];

	}
	studcount--;
	printf("\nDeleted successfully\n");
	printline();



}
