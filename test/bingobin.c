if( (tmp = input_num(check_ary, num, &count, 1)) == 0 )
   break;

for(i=0; i<(num*num); i++)
{
   del_num(user, check_ary[i], num);
   del_num(com, check_ary[i], num);
}

system("cls");
Monitor(user, com, num);

tmp = input_num(check_ary, num, &count, mode);
printf("\n Computer Choose (%d)",tmp);

for(i=0; i<(num*num); i++)
{
   del_num(user, check_ary[i], num);
   del_num(com, check_ary[i], num);
}

fflush(stdln);
getchar();
}
}

