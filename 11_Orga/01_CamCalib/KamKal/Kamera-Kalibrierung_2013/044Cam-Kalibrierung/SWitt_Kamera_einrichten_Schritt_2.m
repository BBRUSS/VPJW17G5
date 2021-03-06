if exist('vid','var')   %Pr�fen ob die Variable 'vid' existiert
    stop(vid);
    delete(vid);
end

% clear all;
clc;
vio_number=1; %Nummer des Video Input Objekt
global flag;
global value;

%Video Input Objekt
vid = videoinput('winvideo',vio_number,'Y800_640x480'); %Erstellen eines Video Input Objektes
set(vid,'TriggerRepeat',Inf);   %Setzen der m�glichen Triggerwiederholungen
set(vid, 'FramesPerTrigger', 1);    %Anzahl Bilder pro Triggerung
triggerconfig(vid,'manual');    %Trigger auf manuel setzen

%Video Source Objekt
vid_src = getselectedsource(vid);   %Erstellen eines Video Source Objektes
% set(vid_src, 'Brightness',0);   %Einstellen der Helligkeit
% set(vid_src, 'Contrast',255);   %Einstellen des Kontrastes
% set(vid_src, 'Exposure',-10);   %Einstellen der Belichtung
% set(vid_src, 'BrightnessMode','manual');

prev=preview(vid);
disp('Objektiv der Kamera einstellen');
input('Um fortzufahren dr�cken sie "Return": ');
delete(prev);

fig2=figure('KeyPressFcn',@bediener_value);     % Grafikfenster einrichten
set(fig2,'Name','Bin_Frame');
bin_frame=transform_frame(frame);
ims2=imshow(bin_frame);
while(auswahl~=4)   %Einstellen des Video Source Objektes
    clc;
    disp('Einstellen des Video Source Objektes');
    disp(['Dr�cken Sie 1 um die Helligkeit einzustellen. Aktueller Wert: ',num2str(Brightness)]);
    disp(['Dr�cken Sie 2 um den Kontrast einzustellen.   Aktueller Wert: ',num2str(Contrast)]);
    disp(['Dr�cken Sie 3 um die Belichtung einzustellen.	Aktueller Wert: ',num2str(Exposure)]);
    disp('Dr�cken Sie 4, wenn sie mit den Video Source Objekt Einstellungen fertig sind.');
    auswahl=input('Mit "Return" best�tigen: ');
    
    switch auswahl
        case 1
            flag=1;
            value=Brightness;
            while(flag)   %Einstellen der Helligkeit
                start(vid); %Aktivieren des Video Input Objektes
                pause(0.1); %Kurze Pause
                clc;
                disp('Einstellen der Helligkeit (Das Figure muss dazu im Vordergrund stehen).');
                disp('Dr�cken Sie "+" um den Wert um 1 und "#" um den Wert um 10 zu erh�hen.');
                disp('Dr�cken Sie "-" um den Wert um 1 und "." um den Wert um 10 zu verringern.');
                disp('Dr�cken Sie "r", wenn Sie fertig sind.');
                disp(['Aktueller Wert: ',num2str(Brightness)]);
                trigger(vid);   %Triggern
                while (vid.FramesAvailable == 0)    %Warten bis Bild vorhanden
                end
                frame = getdata(vid,1); %Bild speichern
                stop(vid);
                if value < 0
                    disp('Endwert Erreicht.');
                    value=0;
                elseif value > 256
                    disp('Endwert Erreicht.');
                    value=256;
                end
                Brightness=value;
                set(vid_src, 'Brightness',Brightness);   %Einstellen der Helligkeit
                set(ims,'CData',frame);
                bin_frame=transform_frame(frame);
                set(ims2,'CData',bin_frame);
            end
            stop(vid);
        case 2
            flag=1;
            value=Contrast;
            while(flag)   %Einstellen des Kontrastes
                start(vid); %Aktivieren des Video Input Objektes
                pause(0.1); %Kurze Pause
                clc;
                disp('Einstellen des Kontrastes (Das Figure muss dazu im Vordergrund stehen).');
                disp('Dr�cken Sie "+" um den Wert um 1 und "#" um den Wert um 10 zu erh�hen.');
                disp('Dr�cken Sie "-" um den Wert um 1 und "." um den Wert um 10 zu verringern.');
                disp('Dr�cken Sie "r", wenn Sie fertig sind.');
                disp(['Aktueller Wert: ',num2str(Contrast)]);
                trigger(vid);   %Triggern
                while (vid.FramesAvailable == 0)    %Warten bis Bild vorhanden
                end
                frame = getdata(vid,1); %Bild speichern
                stop(vid);
                if value < 0
                    disp('Endwert Erreicht.');
                    value=0;
                elseif value > 255
                    disp('Endwert Erreicht.');
                    value=255;
                end
                Contrast=value;
                set(vid_src, 'Contrast',Contrast);   %Einstellen des Kontrastes
                set(ims,'CData',frame);
                bin_frame=transform_frame(frame);
                set(ims2,'CData',bin_frame);
            end
            stop(vid);
        case 3
            flag=1;
            value=Exposure;
            while(flag)   %Einstellen der Belichtung
                start(vid); %Aktivieren des Video Input Objektes
                pause(0.1); %Kurze Pause
                clc;
                disp('Einstellen des Kontrastes (Das Figure muss dazu im Vordergrund stehen).');
                disp('Dr�cken Sie "+" um den Wert um 1 zu erh�hen.');
                disp('Dr�cken Sie "-" um den Wert um 1 zu verringern.');
                disp('Dr�cken Sie "r", wenn Sie fertig sind.');
                disp(['Aktueller Wert: ',num2str(Exposure)]);
                trigger(vid);   %Triggern
                while (vid.FramesAvailable == 0)    %Warten bis Bild vorhanden
                end
                frame = getdata(vid,1); %Bild speichern
                stop(vid);
                if value < -11
                    disp('Endwert Erreicht.');
                    value=-11;
                elseif value > -5
                    disp('Endwert Erreicht.');
                    value=-5;
                end
                Exposure=value;
                set(vid_src, 'Exposure',Exposure);   %Einstellen der Belichtung
                set(ims,'CData',frame);
                bin_frame=transform_frame(frame);
                set(ims2,'CData',bin_frame);
            end
            stop(vid);
        case 4
            break;
        otherwise
            disp('Ung�ltige Eingabe');
            pause(0.5); %Kurze Pause
    end
end
% delete(fig);
delete(fig2);
