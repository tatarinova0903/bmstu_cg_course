package com.example.cg_cource.MainSceneModule;

import com.example.cg_cource.Helpers.MenuEvent;
import com.example.cg_cource.MenuModule.MenuStack;
import com.example.cg_cource.MainSceneModule.Room.RoomGroup;
import javafx.scene.*;


public class MainGroup extends Group {
    RoomGroup roomGroup;

    public MainGroup() {
        RoomGroup roomGroup = new RoomGroup();
        this.roomGroup = roomGroup;
        getChildren().add(roomGroup);
    }

    public void handleEventFromMenu(MenuEvent menuEvent) {
        roomGroup.handleEventFromMenu(menuEvent);
    }
}