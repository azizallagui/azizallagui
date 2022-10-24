#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ensemble
    {
       char dest[10];
       int a;
       int m;
       int j;
    }ensemble;
    typedef struct client
    {
        int ID;
        char nom[10];
        char prenom[10];
        int nbrev;
        ensemble t1[20];
    }client;
int main()
{
    struct ensemble t1[20];
    struct client t0[20];
    int i,nb,ch,test,n1,k,u,aux1,aux2,aux3,max,p,c,rep,ind,s;
    nb=-1;
    int t[20];
    char ch1[10];
    printf("\n|-------------------------------------------------------------------------------------------------------------|");
    printf("\n|-------------menu--------------------------------------------------------------------------------------------|");
    printf("\n|-------------1:Remplir un tableau de n clients---------------------------------------------------------------|");
    printf("\n|-------------2:Afficher le tableau des clients---------------------------------------------------------------|");
    printf("\n|-------------3:Trier les voyages des clients selon l’ordre decroissant de la date----------------------------|");
    printf("\n|-------------4:Afficher le voyageur le plus fidele-----------------------------------------------------------|");
    printf("\n|-------------5:Afficher la destination la plus demandée pour un voyageur sachant son identifiant-------------|");
    printf("\n|-------------6:Afficher le mois de l’année avec le plus grand nombre de réservations-------------------------|");
    printf("\n|-------------0:sortir----------------------------------------------------------------------------------------|");
    printf("\n|-------------------------------------------------------------------------------------------------------------|");
     do
    {
        printf("\n donner votre choix : ");
        scanf("%d",&ch);}
        while ((ch<0)||(ch>6));
     do
     {
     switch(ch)
     {
 case 1:
     printf("donner le nombre de client : ");
     scanf("%d",&nb);
      for (u=0;u<nb;u++)
      {test=-1;
      printf("\n donner le numero de carte d'identite du participant numero %d : ",u+1);
      scanf("%d",&t0[u].ID);
      for (i=0;(i<nb)&&(test<1);i++)
        if (t0[i].ID==t0[u].ID)
            test++;
      if (test>0)
            printf("cet identifiant est deja existe");
      else
      {printf("\n donner le nom du participant : ");
      fflush(stdin);
      gets(t0[u].nom);
      printf("\n donner le prenom du participant : ");
      fflush(stdin);
      gets(t0[u].prenom);
      printf("\n donner le nombre de voyage : ");
      scanf("%d",&t0[u].nbrev);
      n1=t0[u].nbrev;
      for (i=0;i<n1;i++)
      {printf("\n donner la destination de voyage numero %d : ",i+1);
      fflush(stdin);
      gets(t0[u].t1[i].dest);
      do
       {printf("\n donner l'anne du voyage numero %d : ",i+1);
      scanf("%d",&t0[u].t1[i].a);}
      while (t0[u].t1[i].a>2021);
      do
      {printf("\n donner le mois du voyage numero %d : ",i+1);
      scanf("%d",&t0[u].t1[i].m);}
      while ((t0[u].t1[i].m>12)||(t0[u].t1[i].m<1));
      do
      {printf("\n donner le jour du voyage numero %d : ",i+1);
      scanf("%d",&t0[u].t1[i].j);}
      while ((t0[u].t1[i].j>31)||(t0[u].t1[i].j<1));}
      }}
      break;
 case 2:
     i=0;
    for (i=0;i<nb;i++)
    {
     printf("\n %d) \n l'identifiant : %d \n le nom : %s \n le prenom : %s\n le nombre de voyage : %d",i+1,t0[i].ID,t0[i].nom,t0[i].prenom,t0[i].nbrev);
     n1=t0[i].nbrev;
     for (k=0;k<n1;k++)
     {
      printf("\n  la destination de voyage numero %d : %s ",k+1,t0[i].t1[k].dest);
      printf("\n la date du voyage numero %d est : %d/%d/%d  ",k+1,t0[i].t1[k].j,t0[i].t1[k].m,t0[i].t1[k].a);
    }
    printf("\n-------------------------------------------------------");
    }
    break;
 case 3:
    for (i=0;i<nb;i++)
    {
      n1=t0[i].nbrev;
      for (k=0;k<n1-1;k++)
    {
        for (u=k+1;u<n1;u++)
       if ((t0[i].t1[k].a<t0[i].t1[u].a)||((t0[i].t1[k].a==t0[i].t1[u].a)&&(t0[i].t1[k].m<t0[i].t1[u].m))||((t0[i].t1[k].a==t0[i].t1[u].a)&&(t0[i].t1[k].m<t0[i].t1[u].m)&&(t0[i].t1[k].j<t0[i].t1[u].j)))
        {aux1=t0[i].t1[k].a;
       t0[i].t1[k].a=t0[i].t1[u].a;
       t0[i].t1[u].a=aux1;
       aux2=t0[i].t1[k].m;
       t0[i].t1[k].m=t0[i].t1[u].m;
       t0[i].t1[u].m=aux2;
       aux3=t0[i].t1[k].j;
       t0[i].t1[k].j=t0[i].t1[u].j;
       t0[i].t1[u].j=aux3;}

    } }
    break;
 case 4:
    max=0;
    p=0;
    for (i=0;i<=nb;i++)
    {
        if (t0[i].nbrev>max)
           {
            p=i;
            max=t0[i].nbrev;}
    }
    printf("\n le voyageur le plus fidele est %s %s qui a comme identifiant %d",t0[p].prenom,t0[p].nom,t0[p].ID);
    break;
 case 5:
    printf("donner l'identifiant du client : ");
    scanf("%d",&p);
    u=-1;
    for(i=0;(i<=nb)&&(u==-1);i++)
        if (t0[i].ID==p)
        u=i;
    n1=t0[u].nbrev;
    max=0;
    ind=0;
    for (k=0;k<n1-1;k++)
    {
        for(c=k+1;c<n1;c++)
        if (strcmp(t0[u].t1[k].dest,t0[u].t1[c].dest)==0)
            rep=rep+1;
        if (rep>max)
        {
            max=rep;
            ind=k;
        }
    }
    printf("\n la destination la plus demandee pour le client %s qui a comme identifiant %d est : %s ",t0[u].nom,t0[u].ID,t0[u].t1[ind].dest);
    break;
 case 6:
     max=0;
     s=0;
     test=-1;
     for (i=0;i<=nb;i++)
     {n1=t0[i].nbrev;
       for (k=0;k<n1;k++)
       {
          t[s]=t0[i].t1[k].m;
          s++;
       }
     }
     for (i=0;i<s;i++)
     {
         for(u=i+1;u<=s;u++)
         {
             if (t[i]==t[u])
                rep=rep+1;
         }
         if (rep>max)
        {
            max=rep;
            ind=i;
        }
     }
     printf("\n le mois de l'annee avec le plus grand nombre de reservation est ");
     switch (t[ind])
     {
        case 1:
        printf("janvier");
        break;
        case 2:
        printf("fevrier");
        break;
        case 3:
        printf("mars");
        break;
        case 4:
        printf("avril");
        break;
        case 5:
        printf("mai");
        break;
        case 6:
        printf("juin");
        break;
        case 7:
        printf("juillet");
        break;
        case 8:
        printf("aout");
        break;
        case 9:
        printf("septembre");
        break;
        case 10:
        printf("octobre");
        break;
        case 11:
        printf("novembre");
        break;
        case 12:
        printf("decembre");
        break;
     }
    }printf("\n donner un autre choix : ");
    scanf("%d",&ch);}
    while (ch!=0);
    return 0;
}
