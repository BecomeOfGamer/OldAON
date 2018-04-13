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
    $("#button1").click(function() {
      ue4("delete",{});
    });
    $('img').bind('click', function(){
        ue4($(this).attr("id"),{});
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

    for (var i=1;i<=10;++i){
        $('#buff'+i).empty();
    }
    for (var i=1;i<=10;++i){
        if (i <= val.Buff_Amount) {
            var img = $('<img />', {
              id: 'buffimg'+i,
              src: val["Buff"+i+"_Webpath"],
              class: "rounded-circle",
            });
            img.appendTo($('#buff'+i));
            $('#buff'+i).attr('data-original-title', val["Buff"+i+"_Name"])
                .attr("data-content", val["Buff"+i+"_BuffTips"]);    
        } else {
            var img = $('<img />', {
              id: 'buffimg'+i,
              src: '',
              class: "rounded-circle",
            });
            img.appendTo($('#buff'+i));
        }
        
    }
    for (var i=1;i<=val.Skill_Amount;++i){
        $("#skill"+i).attr("src",val["Skill"+i+"_Webpath"]);
    }
    $('[data-toggle="popover"]').popover();
}

$(document).ready(function(){
    for (var i=1;i<=10;++i){
        var div = $('<div />', {
          class: 'col',
          id: 'buff'+i,
          ["data-placement"]:"top",
          ["data-toggle"]: "popover",
          ["data-trigger"]: "hover",
        });
        div.appendTo($('#buffs'));
    }
    /*
    var img = $('<img />', {
          id: 'buffimg1',
          src: 'a07_2.png',
          class: "rounded-circle",
        });
        img.appendTo($('#buff1'));
    
    
    
    $('#buff1')
          .attr('data-original-title', "wwwwww")
          .attr("data-content", "AAA");
          */
});

