// create the global ue4(...) helper function
if (typeof ue == "object" && typeof ue.interface == "object") {
    (function(obj)
    {
        if (typeof obj.broadcast != "function")
            return;

        ue.interface = {};
        ue.interface.broadcast = function(name, data)
        {
            if (typeof data != "undefined")
                obj.broadcast(name, JSON.stringify(data));
            else
                obj.broadcast(name, "");
        };

        ue4 = ue.interface.broadcast;
        
        
        ue.interface.setFPS = function(fps)
        {
            // set element text
            $("#fpsMeter").text(fps.toFixed(1) + " FPS");
        };
        
        ue.interface.setProgress = setProgress;
        ue.interface.hideProgress = hideProgress;
        ue.interface.setCurrentHero = setCurrentHero;

    })(ue.interface);
}    

if (typeof ue4 == "function") {
    ue4("debug",
    {
        "browser": navigator.userAgent,
        "time": Date.now()
    });
}

function hideProgress() {
    $("#pg").slideUp(300);
    $("#status").hide(300);
}

function setProgress(val) {
    $("#pg").show();
    val = val + "%";
    //ue4("debug",{ "v":val});
    $("#pg1").css('width', val);
    $("#pg1").text(val);
}

function setCurrentHero(val) {
    $("#status").show();
    if (typeof ue4 == "function") {
        //ue4("debug",val);
    }
    $("#HeroName").text(val.HeroName);
    $("#CurrentMoveSpeed").text(val.CurrentMoveSpeed);
    $("#CurrentHP").text(val.CurrentHP);
    $("#CurrentMP").text(val.CurrentMP);
    $("#CurrentAttackSpeed").text(Math.floor(val.CurrentAttackSpeed*100));
    $("#CurrentLevel").text(val.CurrentLevel);
    $("#CurrentAttack").text(val.CurrentAttack);
    $("#CurrentArmor").text(val.CurrentArmor);
    $("#CurrentAttackRange").text(val.CurrentAttackRange);
}
