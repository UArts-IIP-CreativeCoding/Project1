int xgrab;
int yfall;
int yfalling;
int yfallstate = 1;
int ellipsefill = 255;
int splatterheight;
int splatterfill = 255;
int splatterstate;
int droplet;
int dropletstate;
int dropletfill = 255;
void setup (){
  background(255);
  size(1024, 768);
  smooth();
}
void draw(){  
  background(255);
  ellipseMode(CENTER);
  fill(ellipsefill);
  noStroke();
  ellipse(xgrab, yfall, 20, 20);
  fill(splatterfill);
  beginShape();
  vertex(xgrab - 200, 768);
  bezierVertex(xgrab - 70, 768, xgrab - 10, 768 + (splatterheight/9), xgrab, splatterheight);
  bezierVertex(xgrab + 10, 768 + (splatterheight/9), xgrab + 70, 768 + (splatterheight/9), xgrab + 200, 768);
  endShape();
  fill(dropletfill);
  noStroke();
  ellipse(xgrab, droplet, 10, 10);
  ellipse(xgrab + random(50), droplet + random(50), 5, 5);
  ellipse(xgrab + random(50), droplet + random(50), 5, 5);
  ellipse(xgrab + random(50), droplet + random(50), 5, 5);
   ellipse(xgrab, droplet, 10, 10);
  ellipse(xgrab - random(50), droplet + random(50), 5, 5);
  ellipse(xgrab - random(50), droplet + random(50), 5, 5);
  ellipse(xgrab - random(50), droplet + random(50), 5, 5);
  
  if(mousePressed){
    xgrab = mouseX;
    yfallstate = 0;
  }
    if(yfallstate == 0){
  yfall+=40;
  ellipsefill = 0;
  splatterstate = 1;
  dropletstate = 1;
}

  if (yfallstate == 3 || yfallstate == 1){
  yfall = 0;
  ellipsefill = 255;
}

  if (yfall >= 768){
  yfallstate = 3;
}
  
   if(dropletstate == 1){
   droplet = 768;

  }
 if (dropletstate == 2) {
  droplet-=13;
     dropletfill = 0;
 }
if (dropletstate == 3) {
 droplet+=3;
    dropletfill = 0;
}

if (dropletstate == 4) {
  droplet+=20;
     dropletfill = 0;
}
  
  if(splatterstate == 1){
    splatterfill = 255;
    splatterheight = 768;
  } 
  
  if(splatterstate == 2){
    splatterfill = 0;
    splatterheight-=10;
  }
  if(splatterstate == 3){
  splatterheight+=13;
  }
  
 if (dropletstate == 1 && yfallstate == 3){
  dropletstate = 2;
}
if (dropletstate == 2 && droplet <= 500){
  dropletstate = 3;
}

if (dropletstate == 3 && droplet >= 510){
  dropletstate = 4;
}


  
  if(splatterstate == 3 && splatterheight >=768){
    splatterstate = 1;
  }
if(splatterheight == 768 && yfallstate == 3){
  splatterstate = 2;
}
if(splatterheight == 568 && yfallstate == 3){
  splatterstate = 3;
}
if(splatterstate == 3 && splatterheight >= 762){
  splatterstate = 1;
  yfallstate = 1;
}

if (yfallstate == 1 && droplet >= 760){
  dropletstate = 1;
  dropletfill = 255;
}



}


