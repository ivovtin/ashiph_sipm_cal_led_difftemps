void draw_npe_u()
{
   //TString name = "npe-f-u_t15_ch1_scan1";    
   //TString name = "npe-f-u_t20_ch1_scan1";     
   //TString name = "npe-f-u_t25_ch1_scan1";    
   //TString name = "npe-f-u_t30_ch1_scan1";    
   //TString name = "npe-f-u_t35_ch1_scan1";    
   //TString name = "npe-f-u_t40_ch1_scan1";    
   //TString name = "npe-f-u_t45_ch1_scan1";    
   TString name = "npe-f-u_t50_ch1_scan1";    

   //TString name = "npe-f-u_t15_ch1_scan2";    
   //TString name = "npe-f-u_t20_ch1_scan2";    
   //TString name = "npe-f-u_t25_ch1_scan2";    
   //TString name = "npe-f-u_t30_ch1_scan2";    
   //TString name = "npe-f-u_t35_ch1_scan2";    
   //TString name = "npe-f-u_t40_ch1_scan2";    
   //TString name = "npe-f-u_t45_ch1_scan2";    
   //TString name = "npe-f-u_t50_ch1_scan2";

   TString fin = "results/" + name + ".dat";
   TString fout = "results/" + name + "_npe_u.png";

   float U[15], npe[15], err_npe[15], freq[15], err_freq[15];

   FILE *f = fopen(fin,"r");
   Int_t i=0;
   while (!feof(f)){
        fscanf(f,"%f %f %f %f %f\n",&U[i],&npe[i],&err_npe[i],&freq[i],&err_freq[i]);
        freq[i] = freq[i];
        err_freq[i] = err_freq[i];
        cout<<i<<"\t"<<U[i]<<"\t"<<npe[i]<<"\t"<<freq[i]<<"\t"<<npe[i]/freq[i]<<endl;
        i++;
   }

   auto g1 = new TGraphErrors(i,U,npe,0,err_npe);

   TCanvas *c1 = new TCanvas();
   c1->SetBorderSize(0);
   c1->SetFillColor(kWhite);
   c1->SetGrid();

   g1->Draw("ALP");
   g1->SetMarkerStyle(21);
   g1->SetTitle(" ; U, V; #mu_{ph.e.}");
   g1->GetYaxis()->SetRangeUser(0, 1.5);

   c1->SaveAs(fout);
} 
