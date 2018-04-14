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

function hideProgress() {
    $("#pg").slideUp(300);
    $("#status").hide(300);
    $("#skills").slideUp(300);
    $("#buffs").slideUp(300);
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
    $("#skills").show();
    $("#buffs").show();
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

    for (var i=1;i<=20;++i){
        if (i <= val.Buff_Amount) {
            $("#buffimg"+i).attr("src",val["Buff"+i+"_Webpath"]);
            $('#buff'+i).attr('data-original-title', val["Buff"+i+"_Name"])
                .attr("data-content", val["Buff"+i+"_BuffTips"]);
            $('#buff'+i).popover();
            $("#buff"+i).show();
        } else {
            $("#buffimg"+i).attr("src","");
            $('#buff'+i).popover("hide");    
            $("#buff"+i).hide();
        }
        
    }
    for (var i=1;i<=6;++i){
        if (i <= val.Skill_Amount) {
            $("#skillimg"+i).attr("src",val["Skill"+i+"_Webpath"]);
            if (val["Skill"+i+"_CanLevelUp"]) {
                $("#skillupimg"+i).attr("src","up.png");
            } else {
                $("#skillupimg"+i).attr("src","");
            }
            $("#skillimg"+i).show();
            $("#skillupimg"+i).show();
            $("#skill"+i).show();
        } else {
            $("#skillimg"+i).attr("src","");
            $("#skillimg"+i).hide();
            $("#skillupimg"+i).hide();
            $("#skill"+i).hide();
        }
    }
}

$(document).ready(function(){
    for (var i=1;i<=20;++i){
        var div = $('<div />', {
          class: '',
          id: 'buff'+i,
          ["data-placement"]:"top",
          ["data-toggle"]: "popover",
          ["data-trigger"]: "hover",
        });
        div.appendTo($('#buffs'));
        var img = $('<img />', {
          id: 'buffimg'+i,
          src: "",
          class: "buffimg rounded-circle",
        });
        img.appendTo($('#buff'+i));
        $("#buff"+i).hide();
    }
    for (var i=1;i<=6;++i){
        var div = $('<div />', {
          class: '',
          id: 'skill'+i,
        });
        div.appendTo($('#skills'));
        var div = $('<div />', {
          class: '',
          id: 'skillu'+i,
          ["data-placement"]:"top",
          ["data-toggle"]: "popover",
          ["data-trigger"]: "hover",
        });
        div.appendTo($('#skill'+i));
        var div = $('<div />', {
          class: '',
          id: 'skilld'+i,
          ["data-placement"]:"top",
          ["data-toggle"]: "popover",
          ["data-trigger"]: "hover",
        });
        div.appendTo($('#skill'+i));
        var img = $('<img />', {
          id: 'skillupimg'+i,
          src: "up.png",
          class: "skillupimg",
        });
        img.appendTo($('#skillu'+i));
        var img = $('<img />', {
          id: 'skillimg'+i,
          src: "",
          class: "skillimg",
        });
        img.appendTo($('#skilld'+i));
        
        $("#skill"+i).hide();
    }
    
    $('img').bind('click', function(){
        ue4($(this).attr("id"),{});
    });
});

