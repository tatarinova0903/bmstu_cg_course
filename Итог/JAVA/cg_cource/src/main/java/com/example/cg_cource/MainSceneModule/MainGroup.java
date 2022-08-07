package com.example.cg_cource.MainSceneModule;

import com.example.cg_cource.Helpers.Material;
import com.example.cg_cource.Helpers.MaterialType;
import com.example.cg_cource.MainSceneModule.Menu.MenuGroup;
import com.example.cg_cource.MainSceneModule.Room.RoomGroup;
import com.example.cg_cource.Objects.Wall;
import javafx.scene.*;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Transform;


public class MainGroup extends Group {
    RoomGroup roomGroup;
    MenuGroup menuGroup;

    public MainGroup() {
        RoomGroup roomGroup = new RoomGroup();
        this.roomGroup = roomGroup;
        getChildren().add(roomGroup);

        MenuGroup menuGroup = new MenuGroup();
        this.menuGroup = menuGroup;
        getChildren().add(menuGroup);
    }
}