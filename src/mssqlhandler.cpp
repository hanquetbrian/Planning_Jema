#include "mssqlhandler.h"

//#include <stdio.h>  // for printf
//#include <SQLAPI.h> // main SQLAPI++ header
#include <iostream>

MssqlHandler::MssqlHandler() {


    //    SAConnection con;
//        try {
//            con.Connect("jemaapp01.jemadom.local@synchro_jema", "JemaQuery01", "Jq@01&", SA_SQLServer_Client);
//            printf("We are connected!\n");

//            SACommand select(&con, "SELECT TOP 20 part_nbr, part_name FROM Synchro_Jema.dbo.D0601200");
//            select.Execute();

//            while(select.FetchNext()) {
//                SAString part_nbr = select[1];
//                SAString part_name = select[2];

//                printf("Nbr: %s, Name: %s \n", (const char*)part_nbr, (const char*)part_name);
//            }
//            /*
//            The rest of the tutorial goes here!
//            */

//            con.Disconnect();
//            printf("We are disconnected!\n");
//        }
//        catch(SAException &x) {
//            con.Rollback();
//            printf("%s\n", (const char*)x.ErrText());
//        }



}
