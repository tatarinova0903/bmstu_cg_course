package com.example.cg_cource.Views;

import javafx.scene.Node;
import javafx.scene.layout.VBox;

public class SmartVBox extends VBox {

    public SmartVBox(Node... nodes) {
        super(nodes);
        setSpacing(10);
        getChildren().forEach(node -> {
            node.setFocusTraversable(false);
        });
    }
}
