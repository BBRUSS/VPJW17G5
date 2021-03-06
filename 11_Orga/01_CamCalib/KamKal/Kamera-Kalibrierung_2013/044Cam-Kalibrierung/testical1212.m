if exist('vid1','var')  %Pr�fen ob die Variable 'vid1' existiert
    stop(vid1);
    delete(vid1);
end
if exist('vid2','var')  %Pr�fen ob die Variable 'vid2' existiert
    stop(vid2);
    delete(vid2);
end
if exist('vid3','var')  %Pr�fen ob die Variable 'vid1' existiert
    stop(vid3);
    delete(vid3);
end
if exist('vid4','var')  %Pr�fen ob die Variable 'vid2' existiert
    stop(vid4);
    delete(vid4);
end

clear all;
clc;

%Video Input Objekt
vid1 = videoinput('winvideo',1,'Y800_640x480'); %Erstellen eines Video Input Objektes
set(vid1,'TriggerRepeat',Inf);   %Setzen der m�glichen Triggerwiederholungen
set(vid1, 'FramesPerTrigger', 1);    %Anzahl Bilder pro Triggerung
triggerconfig(vid1,'manual');    %Trigger auf manuel setzen

vid2 = videoinput('winvideo',2,'Y800_640x480'); %Erstellen eines Video Input Objektes
set(vid2,'TriggerRepeat',Inf);   %Setzen der m�glichen Triggerwiederholungen
set(vid2, 'FramesPerTrigger', 1);    %Anzahl Bilder pro Triggerung
triggerconfig(vid2,'manual');    %Trigger auf manuel setzen

vid3 = videoinput('winvideo',3,'Y800_640x480'); %Erstellen eines Video Input Objektes
set(vid3,'TriggerRepeat',Inf);   %Setzen der m�glichen Triggerwiederholungen
set(vid3, 'FramesPerTrigger', 1);    %Anzahl Bilder pro Triggerung
triggerconfig(vid3,'manual');    %Trigger auf manuel setzen

vid4 = videoinput('winvideo',4,'Y800_640x480'); %Erstellen eines Video Input Objektes
set(vid4,'TriggerRepeat',Inf);   %Setzen der m�glichen Triggerwiederholungen
set(vid4, 'FramesPerTrigger', 1);    %Anzahl Bilder pro Triggerung
triggerconfig(vid4,'manual');    %Trigger auf manuel setzen

%Video Source Objekt
vid_src1 = getselectedsource(vid1);   %Erstellen eines Video Source Objektes
set(vid_src1, 'BrightnessMode','manual');
set(vid_src1, 'Brightness',128);   %Einstellen der Helligkeit
set(vid_src1, 'Contrast',62);   %Einstellen des Kontrastes
set(vid_src1, 'Exposure',-10);   %Einstellen der Belichtung

vid_src2 = getselectedsource(vid2);   %Erstellen eines Video Source Objektes
set(vid_src2, 'BrightnessMode','manual');
set(vid_src2, 'Brightness',128);   %Einstellen der Helligkeit
set(vid_src2, 'Contrast',113);   %Einstellen des Kontrastes
set(vid_src2, 'Exposure',-10);   %Einstellen der Belichtung

vid_src3 = getselectedsource(vid3);   %Erstellen eines Video Source Objektes
set(vid_src3, 'BrightnessMode','manual');
set(vid_src3, 'Brightness',128);   %Einstellen der Helligkeit
set(vid_src3, 'Contrast',113);   %Einstellen des Kontrastes
set(vid_src3, 'Exposure',-10);   %Einstellen der Belichtung

vid_src4 = getselectedsource(vid4);   %Erstellen eines Video Source Objektes
set(vid_src4, 'BrightnessMode','manual');
set(vid_src4, 'Brightness',128);   %Einstellen der Helligkeit
set(vid_src4, 'Contrast',113);   %Einstellen des Kontrastes
set(vid_src4, 'Exposure',-10);   %Einstellen der Belichtung

start(vid1); %Aktivieren des Video Input Objektes
start(vid2); %Aktivieren des Video Input Objektes
start(vid3); %Aktivieren des Video Input Objektes
start(vid4); %Aktivieren des Video Input Objektes
pause(0.5); %Kurze Pause

trigger(vid1);   %Triggern
while (vid1.FramesAvailable == 0)    %Warten bis Bild vorhanden
end
frame1 = getdata(vid1,1); %Bild speichern
figure(1);
imshow(frame1);

trigger(vid2);   %Triggern
while (vid2.FramesAvailable == 0)    %Warten bis Bild vorhanden
end
frame2 = getdata(vid2,1); %Bild speichern
figure(2);
imshow(frame2);

trigger(vid3);   %Triggern
while (vid3.FramesAvailable == 0)    %Warten bis Bild vorhanden
end
frame3 = getdata(vid3,1); %Bild speichern
figure(3);
imshow(frame3);

trigger(vid4);   %Triggern
while (vid4.FramesAvailable == 0)    %Warten bis Bild vorhanden
end
frame4 = getdata(vid4,1); %Bild speichern
figure(4);
imshow(frame4);

% if exist('vid1','var')  %Pr�fen ob die Variable 'vid1' existiert
%     stop(vid1);
%     delete(vid1);
% end
% if exist('vid2','var')  %Pr�fen ob die Variable 'vid2' existiert
%     stop(vid2);
%     delete(vid2);
% end
% if exist('vid3','var')  %Pr�fen ob die Variable 'vid1' existiert
%     stop(vid3);
%     delete(vid3);
% end
% if exist('vid4','var')  %Pr�fen ob die Variable 'vid2' existiert
%     stop(vid4);
%     delete(vid4);
% end