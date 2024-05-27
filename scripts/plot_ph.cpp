
#include <stdio.h>
#include <string.h>
#include "TH2F.h"
#include "TH1F.h"
#include "TProfile.h"

void plot_panel_bias_vs_x_prof_all(){

 TFile *f=TFile::Open("prova.hist");

 TH2F * h0 = (TH2F*)f->Get("TCalStat/trk/plane_0/panel_00/panel_00_x_bias_vs_x_true");
 TH2F * h1 = (TH2F*)f->Get("TCalStat/trk/plane_0/panel_01/panel_01_x_bias_vs_x_true");
 TH2F * h2 = (TH2F*)f->Get("TCalStat/trk/plane_0/panel_02/panel_02_x_bias_vs_x_true");
 TH2F * h3 = (TH2F*)f->Get("TCalStat/trk/plane_0/panel_03/panel_03_x_bias_vs_x_true");
 TH2F * h4 = (TH2F*)f->Get("TCalStat/trk/plane_0/panel_04/panel_04_x_bias_vs_x_true");
 TH2F * h5 = (TH2F*)f->Get("TCalStat/trk/plane_0/panel_05/panel_05_x_bias_vs_x_true");

 h0->RebinX(8);
 h1->RebinX(8);
 h2->RebinX(8);
 h3->RebinX(8);
 h4->RebinX(8);
 h5->RebinX(8);

 TCanvas * c1 = new TCanvas("c1","c1");
 c1->Divide(2,3);
 c1->cd(1);
 TProfile* p0=h0->ProfileX();
 p0->Draw("");
 p0->GetXaxis()->SetTitle("long. pos. [mm]");
 p0->SetTitle("plane0, panel0: profile #Deltax vs x");
 p0->GetYaxis()->SetTitle("prof. #Deltax [mm]");

 c1->cd(2);
 TProfile* p1=h1->ProfileX();
 p1->GetXaxis()->SetTitle("long. pos. [mm]");
 p1->SetTitle("plane0, panel1: profile #Deltax vs x");
 p1->GetYaxis()->SetTitle("prof. #Deltax [mm]");

 p1->Draw("");
 c1->cd(3);
 TProfile* p2=h2->ProfileX();
 p2->GetXaxis()->SetTitle("long. pos. [mm]");
 p2->SetTitle("plane0, panel2: profile #Deltax vs x");
 p2->GetYaxis()->SetTitle("prof. #Deltax [mm]");

 p2->Draw("");
 c1->cd(4);
 TProfile* p3=h3->ProfileX();
 p3->GetXaxis()->SetTitle("long. pos. [mm]");
 p3->SetTitle("plane0, panel3: profile #Deltax vs x");
 p3->GetYaxis()->SetTitle("prof. #Deltax [mm]");

 p3->Draw("");
 c1->cd(5);
 TProfile* p4=h4->ProfileX();
 p4->GetXaxis()->SetTitle("long. pos. [mm]");
 p4->SetTitle("plane0, panel4: profile #Deltax vs x");
 p4->GetYaxis()->SetTitle("prof. #Deltax [mm]");

 p4->Draw("");
 c1->cd(6);
 TProfile* p5= h5->ProfileX();
 p5->GetXaxis()->SetTitle("long. pos. [mm]");
 p5->SetTitle("plane0, panel5: profile #Deltax vs x");
 p5->GetYaxis()->SetTitle("prof. #Deltax [mm]");

 p5->Draw("");
 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/plane0_prof_bias.pdf");
 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/plane0_prof_bias.png");

 //h2->Draw("sames");
}
void plot_myz(){
  
  TFile *f=TFile::Open("prova.hist");
  TH2F * h0 = (TH2F*)f->Get("TCalStat/trk/myz_vs_myz_rec");
  h0->RebinX(4);

  TCanvas * c1 = new TCanvas("c1","c1");
  c1->cd();
  TProfile* p0=h0->ProfileX();
  p0->Draw("");
  p0->GetXaxis()->SetTitle("m_{yz,true}");
  p0->SetTitle("profile m_{yz,rec} vs m_{yz,true}");
  p0->GetYaxis()->SetTitle("m_{yz,rec}");

  p0->Draw("");
 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/myz_vs_myz_rec_prof.pdf");
 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/myz_vs_myz_rec_prof.png");


}
void plot_mxy(){
  TFile *f=TFile::Open("prova.hist");
  TH2F * h0 = (TH2F*)f->Get("TCalStat/trk/mxy_vs_mxy_rec");
  h0->RebinX(4);

  TCanvas * c1 = new TCanvas("c1","c1");
  c1->cd();
  TProfile* p0=h0->ProfileX();
  p0->Draw("");
  p0->GetXaxis()->SetTitle("m_{yx,true}");
  p0->SetTitle("profile m_{yx,rec} vs m_{yx,true}");
  p0->GetYaxis()->SetTitle("m_{yx,rec}");

  p0->Draw("");
  c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/myx_vs_myx_rec_prof.pdf");
  c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/myx_vs_myx_rec_prof.png");

}


void plot_panel_0(){

 TFile *f=TFile::Open("prova.hist");

 TH2F * h0 = (TH2F*)f->Get("TCalStat/trk/plane_0/panel_00/panel_00_xp_vs_yp");

 TCanvas * c1 = new TCanvas("c1","c1");
 c1->cd(1);
 h0->Draw("");
 h0->GetYaxis()->SetRangeUser(300.,800.);

 h0->GetXaxis()->SetRangeUser(700.,-700.);
 h0->GetXaxis()->SetTitle("x_{panel} [mm]");
 h0->SetTitle("plane0, panel0: x vs y, panel frame");
 h0->GetYaxis()->SetTitle("y_{panel} [mm]");
 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/xp_vs_yp_panel0.pdf");
 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/xp_vs_yp_panel0.png");

 //h2->Draw("sames");
}


void plot_panel_bias_vs_x_prof_0(){

 TFile *f=TFile::Open("prova.hist");

 TH2F * h0 = (TH2F*)f->Get("TCalStat/trk/plane_0/panel_00/panel_00_x_bias_vs_x_true");

 TCanvas * c2 = new TCanvas("c2","c2");
 c2->cd(1);
 h0->Draw("");
 h0->GetXaxis()->SetTitle("long. pos. [mm]");
 h0->SetTitle("plane0, panel0: #Deltax vs x_{true}");
 h0->GetYaxis()->SetTitle("#Deltax [mm]");
 h0->SetMarkerStyle(7);

 c2->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/panel_00_x_bias_vs_x.pdf");
 c2->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/panel_00_x_bias_vs_x.png");

 h0->RebinX(8);

 TCanvas * c1 = new TCanvas("c1","c1");
 c1->cd(1);
 TProfile* p0=h0->ProfileX();
 p0->Draw("");
 p0->GetXaxis()->SetTitle("long. pos. [mm]");
 p0->SetTitle("plane0, panel0: profile #Deltax vs x");
 p0->GetYaxis()->SetTitle("prof. #Deltax [mm]");
 p0->SetMarkerStyle(1);

 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/panel_00_x_bias_vs_x_prof.pdf");
 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/panel_00_x_bias_vs_x_prof.png");

 //h2->Draw("sames");
}


void plot_x_bias(){

 TFile *f=TFile::Open("prova.hist");

 TH1F * h0 = (TH1F*)f->Get("TCalStat/trk/plane_0/panel_00/panel_00_x_bias");

 TCanvas * c1 = new TCanvas("c1","c1");
 c1->cd(1);
 h0->Draw("");
 h0->SetFillColor(4);
 h0->SetFillStyle(3002);
 h0->SetBarWidth(0.84);
 h0->SetBarOffset(0.5);
 h0->GetXaxis()->SetRangeUser(-200.,200.);
 h0->GetXaxis()->SetTitle("x_{panel} [mm]");
 h0->SetTitle("plane0, panel0: #Deltax, panel frame");
 h0->GetYaxis()->SetTitle("counts");
 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/panel_00_x_bias.pdf");
 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/panel_00_x_bias.png");

 //h2->Draw("sames");
}


void plot_myz_all(){

 TFile *f=TFile::Open("prova.hist");

 TH1F * h0 = (TH1F*)f->Get("TCalStat/trk/myz");

 TCanvas * c1 = new TCanvas("c1","c1");
 c1->cd(1);
 h0->Draw("");
 h0->SetFillColor(4);
 h0->SetFillStyle(3002);
 h0->SetBarWidth(0.84);
 h0->SetBarOffset(0.5);
 h0->GetXaxis()->SetTitle("m_{yz,true}");
 h0->SetTitle("m_{yz,true} distribution");
 h0->GetYaxis()->SetTitle("counts");
 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/myz.pdf");
 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/myz.png");

 TH1F * h1 = (TH1F*)f->Get("TCalStat/trk/myz_rec");

 TCanvas * c2 = new TCanvas("c2","c2");
 c2->cd(2);
 h1->Draw("");
 h1->SetFillColor(4);
 h1->SetFillStyle(3002);
 h1->SetBarWidth(0.84);
 h1->SetBarOffset(0.5);
 h1->GetXaxis()->SetTitle("m_{yz,rec}");
 h1->SetTitle("m_{yz,rec} distribution");
 h1->GetYaxis()->SetTitle("counts");
 c2->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/myz_rec.pdf");
 c2->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/myz_rec.png");

 TH1F * h2 = (TH1F*)f->Get("TCalStat/trk/myz_vs_myz_rec");

 TCanvas * c3 = new TCanvas("c3","c3");
 c3->cd(3);
 h2->Draw("");
 h2->SetFillColor(4);
 h2->SetFillStyle(3002);
 h2->SetBarWidth(0.84);
 h2->SetBarOffset(0.5);
 h2->GetXaxis()->SetTitle("m_{yz,true}");
 h2->SetTitle("m_{yz,rec} vs m_{yz,true}");
 h2->GetYaxis()->SetTitle("m_{yz,rec}");
 c3->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/myz_vs_myz_rec.pdf");
 c3->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/myz_vs_myz_rec.png");

}



void plot_mxy_all(){

 TFile *f=TFile::Open("prova.hist");

 TH1F * h0 = (TH1F*)f->Get("TCalStat/trk/mxy");

 TCanvas * c1 = new TCanvas("c1","c1");
 c1->cd(1);
 h0->Draw("");
 h0->SetFillColor(4);
 h0->SetFillStyle(3002);
 h0->SetBarWidth(0.84);
 h0->SetBarOffset(0.5);
 h0->GetXaxis()->SetTitle("m_{yx,true}");
 h0->SetTitle("m_{yx,true} distribution");
 h0->GetYaxis()->SetTitle("counts");
 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/mxy.pdf");
 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/mxy.png");

 TH1F * h1 = (TH1F*)f->Get("TCalStat/trk/mxy_rec");

 TCanvas * c2 = new TCanvas("c2","c2");
 c2->cd(2);
 h1->Draw("");
 h1->SetFillColor(4);
 h1->SetFillStyle(3002);
 h1->SetBarWidth(0.84);
 h1->SetBarOffset(0.5);
 h1->GetXaxis()->SetTitle("m_{yx,rec}");
 h1->SetTitle("m_{yx,rec} distribution");
 h1->GetYaxis()->SetTitle("counts");
 c2->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/mxy_rec.pdf");
 c2->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/mxy_rec.png");

 TH1F * h2 = (TH1F*)f->Get("TCalStat/trk/mxy_vs_mxy_rec");

 TCanvas * c3 = new TCanvas("c3","c3");
 c3->cd(3);
 h2->Draw("");
 h2->SetFillColor(4);
 h2->SetFillStyle(3002);
 h2->SetBarWidth(0.84);
 h2->SetBarOffset(0.5);
 h2->GetXaxis()->SetTitle("m_{yx,true}");
 h2->SetTitle("m_{yx,rec} vs m_{yx,true}");
 h2->GetYaxis()->SetTitle("m_{yx,rec}");
 c3->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/myx_vs_myx_rec.pdf");

 c3->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/myx_vs_myx_rec.png");


}


void plot_x(){

 TFile *f=TFile::Open("prova.hist");

 TH2F * h0 = (TH2F*)f->Get("TCalStat/trk/plane_0/panel_00/panel_00_x");

 TCanvas * c1 = new TCanvas("c1","c1");
 c1->cd(1);
 h0->Rebin(8);

 h0->Draw("");
 h0->SetFillColor(4);
 h0->SetFillStyle(3002);
 h0->SetBarWidth(0.84);
 h0->SetBarOffset(0.5);
 h0->GetXaxis()->SetTitle("x_{panel} [mm]");
 h0->GetYaxis()->SetTitle("counts");

 h0->SetTitle("plane0, panel0: x, panel frame");
 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/x_panel0.pdf");
 c1->SaveAs("/exp/mu2e/app/users/sgamba/r002/tracker_meeting/figures/pdf/x_panel0.png");

 //h2->Draw("sames");
}


void plot_all(){
  plot_mxy();
  plot_mxy_all();
  plot_myz();
  plot_myz_all();
  plot_panel_0();
  plot_panel_bias_vs_x_prof_0();
  plot_panel_bias_vs_x_prof_all();
  plot_x_bias();
  plot_x();
  return;
}





