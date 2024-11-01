void draw_t_u_f()
{
   //channel 1
   //double T[8] = { 15, 20, 25, 30, 35, 40, 45, 50 };
   //double U[8] = { 53.5, 54., 54.5, 55., 55.5, 56., 57., 57.5};
   //double f[8] = { 1.6029150, 1.91953, 2.7342600, 3.39746, 4.5180050, 6.95835, 8.83672, 9.6177550 };
   //double ef[8] = { 0.654042, 0.505715, 0.393270, 0.258246, 0.200674, 0.85611, 0.41817, 0.026495 };

   //channel 2
   double T[8] = { 15, 20, 25, 30, 35, 40, 45, 50 };
   double U[8] = { 53.5, 54., 54.5, 55., 55.5, 56., 57., 58.};
   double f[8] = { 1.3665950, 1.88854, 2.6454350, 3.58553, 5.0428500, 6.83272, 8.68576, 9.68879 };
   double ef[8] = { 0.776233, 0.520396, 0.415425, 0.243631, 0.170829, 0.089810, 0.045788, 0.019768 };

   TCanvas *c1 = new TCanvas();
   c1->cd();
   auto g = new TGraphErrors(8,T,U,0,0);

   g->SetMarkerStyle(21);

   g->SetTitle(" ; T, C; U, V");
   //g->GetYaxis()->SetRangeUser(0, 6.0); 
   g->Draw("ALP");

   c1->SaveAs("results/U-T.png");
   
   TCanvas *c2 = new TCanvas();
   c2->cd();
   auto g2 = new TGraphErrors(8,T,f,0,ef);
   //auto g2 = new TGraphErrors(8,T,f,0,0);

   g2->SetMarkerStyle(21);

   g2->SetTitle(" ; T, C; Frequency, MHz");
   g->GetYaxis()->SetRangeUser(0, 10.0); 
   g2->Draw("ALP");

   c2->SaveAs("results/F-T.png");
   
}
