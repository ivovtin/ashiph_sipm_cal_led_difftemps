void draw_f_u()
{
   TString name = "f_u_T15";	

   TString fin = "results/" + name + ".dat";
   TString fout = "results/" + name + ".png";

   float U[15], fr[15], err_fr[15];

   FILE *f = fopen(fin,"r");
   Int_t i=0;
   while (!feof(f)){
	fscanf(f,"%f %f %f\n",&U[i],&fr[i],&err_fr[i]);
	cout<<i<<"\t"<<U[i]<<"\t"<<fr[i]<<endl;
	i++;
   }
 
   auto g1 = new TGraphErrors(i,U,fr,0,err_fr);

   TCanvas *c1 = new TCanvas();
   c1->SetBorderSize(0);
   c1->SetFillColor(kWhite);
   c1->SetGrid();

   g1->Draw("ALP");
   g1->SetMarkerStyle(21);
   g1->SetTitle(" ; U, V; Frequency, MHz");
   g1->GetYaxis()->SetRangeUser(0, 3.5);

   c1->SaveAs(fout);
} 
