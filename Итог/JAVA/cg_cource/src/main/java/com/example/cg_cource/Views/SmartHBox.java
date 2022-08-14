package com.example.cg_cource.Views;

import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.layout.HBox;

public class SmartHBox extends HBox {
    public SmartHBox(Node... nodes) {
        super(nodes);
        setSpacing(10);
        setAlignment(Pos.CENTER);
        getChildren().forEach(node -> {
            node.setFocusTraversable(false);
        });
    }
}
