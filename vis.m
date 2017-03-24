global text1 slider1 NewImageShowHandle map data
MainFigure=figure('menubar','none','numbertitle','off','position',[100 100 1200 600],'name','slide and text');
text1=uicontrol('style','edit','parent',MainFigure,'position',[120 22 50 20],'string','0','callback',@text1_callback);
slider1=uicontrol('style','slider','parent',MainFigure,'position',[200 20 800 20],'callback',@slider1_callback);

map=csvread('map.dat');
data=csvread('stream.dat');
slider1.Min = 0;
slider1.Max = (length(data)-1)*0.05;

slider1.SliderStep = [1/20/slider1.Max 20*1/20/slider1.Max];

border = 2;
NewImageShowHandle=axes('xlim',[-border 70+border],'ylim',[-border 52+border],'Units','normalized','position',[0.02 0.1 .95 .88],'Parent',MainFigure);

draw_map(0.0);

function draw_map(t)
    global map data NewImageShowHandle
    hold on
    k = round(t / 0.05) + 1;
    for i = 1:48
        p = [map(i,2),map(i,5),map(i,4)-map(i,2),map(i,3)-map(i,5)];
        rectangle('Position',p,'LineWidth',0.6,'LineStyle','-','FaceColor',[0.8 1.0 0.8],'Parent',NewImageShowHandle);
        text(map(i,2),map(i,5)+0.6,num2str(i-1),'Parent',NewImageShowHandle)
    end
%     plot(data(k,2),data(k,3),'b*','Parent',NewImageShowHandle);
%     text(data(k,2)-1,data(k,3)+1,'Robot 0','Color','b','Parent',NewImageShowHandle)
%     
%     plot(data(k,4),data(k,5),'b*','Parent',NewImageShowHandle);
%     text(data(k,4)-1,data(k,5)+1,'Robot 1','Color','b','Parent',NewImageShowHandle)
% 
%     plot(data(k,6),data(k,7),'r*','Parent',NewImageShowHandle);
%     text(data(k,6)-1,data(k,7)+1,'Human 0','Color','r','Parent',NewImageShowHandle)
% 
%     plot(data(k,8),data(k,9),'r*','Parent',NewImageShowHandle);
%     text(data(k,8)-1,data(k,9)+1,'Human 1','Color','r','Parent',NewImageShowHandle)

end

function slider1_callback(hObject, event)
    global text1 NewImageShowHandle
    t = round(get(hObject,'value')*20)/20.0;
    set(hObject,'value',t);
    set(text1,'string',num2str(get(hObject,'value')))

    global map data
    hold off
    k = round(t / 0.05) + 1;
    for i = 1:48
        p = [map(i,2),map(i,5),map(i,4)-map(i,2),map(i,3)-map(i,5)];
        rectangle('Position',p,'LineWidth',0.6,'LineStyle','-','FaceColor',[0.8 1.0 0.8],'Parent',NewImageShowHandle);
        text(map(i,2),map(i,5)+0.6,num2str(i-1),'Parent',NewImageShowHandle)
        if i==2
            hold on
        end
    end
    plot(data(k,2),data(k,3),'b*','Parent',NewImageShowHandle);
    text(data(k,2)-1,data(k,3)+1,'Robot 0','Color','b','Parent',NewImageShowHandle)
    
    plot(data(k,4),data(k,5),'b*','Parent',NewImageShowHandle);
    text(data(k,4)-1,data(k,5)+1,'Robot 1','Color','b','Parent',NewImageShowHandle)

    plot(data(k,6),data(k,7),'r*','Parent',NewImageShowHandle);
    text(data(k,6)-1,data(k,7)+1,'Human 0','Color','r','Parent',NewImageShowHandle)

    plot(data(k,8),data(k,9),'r*','Parent',NewImageShowHandle);
    text(data(k,8)-1,data(k,9)+1,'Human 1','Color','r','Parent',NewImageShowHandle)


    pause(0.0001)
end

function text1_callback(hObject, event)
    global slider1
    set(slider1,'value',str2num(get(hObject,'string')))
end

