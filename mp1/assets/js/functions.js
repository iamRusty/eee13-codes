function display1(dest, key, slot)
{

	var name = "linenum=";
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }
//	alert(count);
	switch (count)
	{
		case 0:	
			document.getElementById("textField1").value = "Waking up, you find yourself in a dimly-lit and dirty room. The tiled floors stained with dark mold on the grout probably from dried out blood - and there is even a fresh puddle of blood in the middle.";
			break;
		case 1:
			document.getElementById("textField1").value = "The air feels cold and damp and smells stale- how many hours, no days how you been here. You feel a sharp pain around where your back has been pressed to the hard tiles- and you feel chafing around your wrists and ankles from cufflinks and manacles.";
			break;
		case 2:
			document.getElementById("textField1").value = "Only then have you realized that you are being help captive- then suddenly static voice echoes from a PA speaker in the opposite corner of the room.";
			break;
		case 3:
			document.getElementById("textField1").value = "Voice: Rise and shine, Boy. You\'re probably wondering where you are. I\'ll tell you where you might be. You might be in the room you die in.";
			break;
		case 4:
			document.getElementById("textField1").value = "Voice: Up until now you lurked in the shadows- observing the lives of others and seeking out their secrets.";
			break;
		case 5:
			document.getElementById("textField1").value ="Voice: Behind the mask of ANONYMOUS- you call yourselves, you acted to right the \'injustices\' that you see that no one dared act on- but mostly it was for the lulz.";
			break;
		case 6:
			document.getElementById("textField1").value ="Voice: Now you find yourself the hapless target now- though unlike most of your victims you have a bit of talent for this, for all the good and bad it has done.";
			break;
		case 7:
			document.getElementById("textField1").value ="Voice: So are you going to watch yourself die today, Boy, or do something about it?";
			break;
		case 8:
			document.getElementById("textField1").value ="I d-don\'t- who are You!";
			break;
		case 9:
			document.getElementById("textField1").value ="Voice: It does not matter who I am- I am simply anonymous. Hmm.. I think it rather befits me more than you now, doesn\'t it?.";
			break;
		case 10:
			document.getElementById("textField1").value ="But what I really want now, is to play a game.";
			break;
		case 11:
			document.getElementById("textField1").value ="I\'m giving you 5 challenges of ascending difficulty- prove that you are not just some script kiddie doing this for the lulz and you may live to right the injustices of the world as you see again.";
			break;
		case 12:
			document.getElementById("textField1").value ="But, don\'t get cocky just yet- each mistake and I reserve the right to punish you as I see fit.";
			break;
		case 13:
			document.getElementById("textField1").value ="After completing each challenge I will reward you favors that you can use to exchange for stuff that will help you in your brief stay here.";
			break;
		case 14:
		{
			post('scene1dec.cgi', {'scene1dec.cgi': slot});
			break;
		}
	}

	count++;
	document.cookie="linenum=" + count + "; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
	return 1;
}

function display2(slot)
{

	var name = "linenum=";
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }
//	alert(count);
	switch (count)
	{
		case 0:	
			document.getElementById("textField1").value = "After a few moments of hearing the announcement, panic seeped in. Realizing you might really die here, you pull the chains from the wall pegs as hard as you can,";
			break;
		case 1:
			document.getElementById("textField1").value = "the iron digging into your chafed skin. However, try as you might, they wont come undone.";
			break;
		case 2:
			document.getElementById("textField1").value = "You scan around the room, you see a broom handle, a thread, a small piece of fishing hook, some dirty bottles, a couple of scattered first aid kits, a packet of painkillers";
			break;
		case 3:
			document.getElementById("textField1").value = "and in the far corner of the room a small glimmer of light- a set of keys. But its too far from you- no matter how far you stretch. The broom handle could maybe reach it.";
			break;
		case 4:
			document.getElementById("textField1").value = "You: <Reach out for broom handle>";
			break;
		case 5:
			document.getElementById("textField1").value ="Arghh! You cant reach it too! Panic seeps in as you curse and pull the chains. You then try to scream for help.";
			break;
		case 6:
			document.getElementById("textField1").value ="HELPPPP! ANYONE?!?!?!?!?!";
			break;
		case 7:
			document.getElementById("textField1").value ="As your tired voice echoes throughout the room, it dawns upon you that there really is no way of this- there is no one to help, but yourself alone. and you then just sit there waiting for the upcoming challenge...";
			break;
		case 8:
			document.getElementById("textField1").value ="You: <Doze off...>";
			break;
		case 9:
			post('scene3.cgi', {'scene3.cgi': slot});
			break;
	}

	count++;
	document.cookie="linenum=" + count + "; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
	return 1;
}


function display3(slot)
{

	var name = "linenum=";
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }
//	alert(count);
	switch (count)
	{
		case 0:	
			document.getElementById("textField1").value = "You are sitting in your favorite cafe- waiting for your gf partner in crime. Whats taking her so long? A waiter walks to your table and asks for your order for the nth time now.";
			break;
		case 1:
			document.getElementById("textField1").value = "She arrives as your drink do.";
			break;
		case 2:
			document.getElementById("textField1").value = "GF: Aw, you didn\'t wait for me before ordering your drink, You must be thirsty already.";
			break;
		case 3:
		{
			var choice = prompt("You: What took you so long?\na) Well, what took you so long? We still have a deadline to finish, and meeting here in broad daylight is dangerous enough.\nb) Well, of course. I waited for you- its just that I cant really talk as much as I would like to you with a dry mouth. <Stand and offer her her seat>\nc) Well, I ordered something for you too.<You're lying>");
			if (choice=='a')
			{
				document.getElementById("textField1").value = "Oh, so would rather talk behind screens then, fine we\'ll talk online. <And She storms off>";
			}
			else if (choice=='b')
			{
				document.getElementById("textField1").value = "She smiles as she takes the eat and orders something. You then talk about the project";
			}
			else if (choice=='c')
			{
				document.getElementById("textField1").value = "Oh really, you shouldn\'t have. However it only takes a few minutes before she notices you didn\'t really. She doesn\'t talk to you for the whole time- just through texts on her phone";
			}
			else
			{
				document.getElementById("textField1").value = "Oh so you prefer to stay silent, uh? Ok, we're done! Good riddance, beansprout!.";
			}
			break;
		}
		case 4:
			post('scene4.cgi', {'scene4.cgi': slot});
			break;
	}

	count++;
	document.cookie="linenum=" + count + "; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
	return 1;
}
var choice2;
function display4(slot)
{

	var name = "linenum=";
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }
//	alert(count);
	switch (count)
	{
		case 0:	
			document.getElementById("textField1").value = "Suddenly a sharp sudden pain jolts you awake from your dream- a strange collar is now around your neck, along with the smell of electrically charred flesh.";
			break;
		case 1:
			document.getElementById("textField1").value = "An old laptop that has a broken screen and only a few keys now sits in front of you. The text on the screen says:";
			break;
		case 2:
			document.getElementById("textField1").value = "Voice: Sorry for the equipment- I could have brought you something more usable but then all those chains and the collar cost me a lot of money already.";
			break;
		case 3:
			document.getElementById("textField1").value = "Voice: If youd like I can arrange for a new one to be brought here though you would have to pay, don\'t worry I can wait.";
			break;
		case 4:
			document.getElementById("textField1").value = "Voice: Just click on the bookmarked wireless transfer and send to the other bookmarked link to send me the money to buy you a new one- of course you would just have to trust me on this.”- S";
			break;
		case 5:
			document.getElementById("textField1").value = "The broken screen shows a webpage for wireless fund transfer- it then prompts you for your account credentials.";
			break;
		case 6:
		{
			choice2=prompt("a) <Type in your account>\nb)\"Nah, I think this will do\"\nc)\"Screw you, this deal is a scam\"");
			if (choice2=='a')
			{
				document.getElementById("textField1").value = "Voice: Eeengk! Wrong, did you not notice the https – that should have been a red flag to you hackers- such poor showing for your first-keep this up and youll be dead.";
			}
			else if (choice2=='b')
			{
				document.getElementById("textField1").value = "Voice: You refuse, very well though I must say you will need every bit of help I offer You if you are to survive this.";
			}
			else if (choice2=='c')
			{
				document.getElementById("textField1").value = "Voice: That\'s enough, you\'ve shown that you don\'t really need a decent machine – I think this one will do. But don\'t worry, your effort will be rewarded, you earn a favor from me- it will be of greater help to you than any machine- after all its only your life that is at stake here.";
			}
			else
			{
				document.getElementById("textField1").value = "Voice: I\'ll take it as option b. You refuse, very well though I must say you will need every bit of help I offer You if you are to survive this.";
			}

			break;
		}
		case 7:
		{
			if (choice2=='a')
				alert("Voice: You are not worthy enough to take my challenge afterall.");
			else if (choice2=='b')
				alert("+0 HP");
			else if (choice2=='c')
				alert("+1 favor");
			else
				alert("+0 HP");

			break;
		}
		case 8:
		{
			if (choice2=='a')
				window.location.replace("dead.cgi");
			else if (choice2=='b')
				post('scene4norm.cgi', {'scene4norm.cgi': slot});
			else if (choice2=='c')
				post('scene4plus.cgi', {'scene4plus.cgi': slot});
			else
				post('scene4norm.cgi', {'scene4norm.cgi': slot});

			break;
		}	
	}
	

	count++;
	document.cookie="linenum=" + count + "; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
	return 1;
}

function display5(slot)
{

	var name = "linenum=";
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }
//	alert(count);
	switch (count)
	{
		case 0:	
			document.getElementById("textField1").value = "You may have noticed already the number besides \"Inventory\". That is your money for this whole challenge. Let me tell you what I got for you and their corresponding price:";
			break;
		case 1:
			document.getElementById("textField1").value = "Item 1: Health Potion(HP) - 1 favor";
			break;
		case 2:
			document.getElementById("textField1").value = "Item 2: Slender Resist(SR) - 3 favors, yes, Slender is my pet. He will be haunting you as you clear the challenges. They say that an ounce of prevention is worth a pound of cure, so you might need this.";
			break;
		case 3:
			document.getElementById("textField1").value = "Item 3: Trap Resist(TRR) - 3 favors. I just love traps. eh?.";
			break;
		case 4:
			document.getElementById("textField1").value = "You still can\'t buy anything from here since you don\'t have enough favor. You still have to prove your worth to me.";
			break;
		case 5:
			document.getElementById("textField1").value = "Now, have I already mentioned that the harder the challenge is, the more rewarding it gets?";
			break;
		case 6:
			document.getElementById("textField1").value ="You can always tell me via the store bookmark what you want even if it\'s the middle of challenge";
			break;
		case 7:
				post('scene6.cgi', {'scene6.cgi': slot});
			break;

	}

	count++;
	document.cookie="linenum=" + count + "; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
	return 1;
}
var choice6;
function display6(slot)
{

	var name = "linenum=";
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }
//	alert(count);
	switch (count)
	{
		case 0:	
			document.getElementById("textField1").value = "As you wait, you find yourself dozing off yet again- the stress and the crash from the adrenaline weighing you down. As you rest your head on the wall you feel something behind you shift,";
			break;
		case 1:
			document.getElementById("textField1").value = "You turn around a bit to see a log book in a crevice in the wall- a clean page for you to write on is dog-eared. You see that written on the top row is :";
			break;
		case 2:
			document.getElementById("textField1").value = "Save Number - Time Stamp - Inventory - Health";
			break;
		case 3:
			document.getElementById("textField1").value = "Which is clearly some kind of progress record- perhaps others who have been trapped here used this to keep track of the days. Should be helpful.";
			break;
		case 4:
		{
			choice6 = prompt("Save or No?\na)Save\notherwise, No");
			if (choice6=='a')
			{
				document.getElementById("textField1").value = "As you write your progress, you hope it wont take long before you write your last entry- dead or alive afterwards.";

			}
			else
				document.getElementById("textField1").value = "After some thoughts, you think that keeping a progress log for yourself will just make you depressed.";

			break;
		}
		case 5:
		{
			if (choice6=='a')
				post('save.cgi', {'scene6.cgi': slot});
			else
				post('scene7.cgi', {'scene7.cgi': slot});
			break;
		}

	}

	count++;
	document.cookie="linenum=" + count + "; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
	return 1;
}


var choice7;
function display7(slot)
{

	var name = "linenum=";
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }
//	alert(count);
	switch (count)
	{
		case 0:	
			document.getElementById("textField1").value = "You waited for a couple of hours now, and it seems your captor is not coming back until the next day. You choose to sleep for a while, thinking about the challenge.";
			break;
		case 1:
			document.getElementById("textField1").value = "GF: Arghh, this site is blocked! None of the webproxies I know work either- and im too lazy to setup a VPN over this thing.";
			break;
		case 2:
		{
			choice7 = prompt("Boy, do you know of a way to connect?\na)YES\notherwise, NO");
			if (choice7=='a')
				document.getElementById("textField1").value = "GF: well show me- <wait for a while> wait you don\'t really know don\'t you.";
			else
				document.getElementById("textField1").value = "GF: well its fine, I think I remember a way while I was talking to you.";
			break;
		}
		case 3:
			document.getElementById("textField1").value = "GF:Its through Google Translate- basically you paste the website url in it, the languages don\'t matter. Then open it. Et voila! I can now access it- thanks you by the way, good for nothing.";
			break;
		case 4:
				post('scene8.cgi', {'scene8.cgi': slot});
			break;
			

	}

	count++;
	document.cookie="linenum=" + count + "; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
	return 1;
}

var choice8;
function display8(slot)
{

	var name = "linenum=";
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }
//	alert(count);
	switch (count)
	{
		case 0:	
			document.getElementById("textField1").value = "Voice: How\'s the sleep, dreamt well? Well you better, since you might just die today- if you don\'t do well. No point in delaying then, this is your challenge.";
			break;
		case 1:
			document.getElementById("textField1").value = "<A prompt appears>";
			break;
		case 2:
		{
			choice7 = prompt("This is a do or die question.\nType the title of the Naruto Chapter 582");
			if ((choice7=='Nothing')||(choice7=='nothing'))
				document.getElementById("textField1").value = "Hmm, lucky? Very well, I owe you 2 favors.";
			else
				document.getElementById("textField1").value = "Wrong! Perhaps you are not just as talented as I thought you were- here's your punishment!";
			break;
		}
		case 3:
		{
			if ((choice7=='Nothing')||(choice7=='nothing'))
			{
				alert("+2 Favors");
				document.getElementById("textField1").value = "Now, the next challenge would be related to what You mostly do: hacking. The most basic of all really. You just have to guess someones password. Now good luck and get some sleep- you\'re gonna need it.";
			}
			else
				window.location.replace("dead.cgi");
			break;
		}
		case 4:
		{
				post('scene8plus.cgi', {'scene8plus.cgi': slot});
			break;
		}
			

	}

	count++;
	document.cookie="linenum=" + count + "; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
	return 1;
}

function display9(slot)
{

	var name = "linenum=";
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }
//	alert(count);
	switch (count)
	{
		case 0:	
			document.getElementById("textField1").value = "You order coffee. You drink the beverage, its nice. The place is nice too, but of course. Nothing is as nice as the chick sitting in front of you now.";
			break;
		case 1:
			document.getElementById("textField1").value = "GF: Well, isn\'t this interesting- says here that someone managed to hack into a politician\'s account through googling her biographical information then using it to gain access into her real password.";
			break;
		case 2:
		{
			document.getElementById("textField1").value = "Clever, I think I have a couple of names I would like to try with. <Gets back into computer>";
			break;
		}
		case 3:
		{
			document.getElementById("textField1").value = "GF: And, yes, success. It does work- though im pretty sure this would only work if the target is really tech dumb.";
			break;
		}
		case 4:
				post('scene10.cgi', {'scene10.cgi': slot});
			break;
			

	}

	count++;
	document.cookie="linenum=" + count + "; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
	return 1;
}

function display10(slot)
{

	var name = "linenum=";
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }
//	alert(count);
	switch (count)
	{
		case 0:	
			document.getElementById("textField1").value = "You wake up you to find yourself free of your restraints. The items on the floor are gone, except for the little that you have. You then gaze to the 3 opened doors and your hope rises.";
			break;
		case 1:
			document.getElementById("textField1").value = "Voice: Calm yourself Boy. You are still not free from me. You have to choose which path to take. Don't worry, there sure is a door there that will lead to the path of your freedom.";
			break;
		case 2:
			document.getElementById("textField1").value = "Oh, by the way, once you step beyond any of the door, all the doors will automatically close and lock. Of the 3 doors, 1 can be unlocked.";
			break;
		case 3:
		{
			document.getElementById("textField1").value = "Please choose which path you\'ll be going to.";
			break;
		}	

	}

	count++;
	document.cookie="linenum=" + count + "; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
	return 1;
}
var sceneback;
function slender(sceneback)
{
	var name = "slender=";
	var i;
	var type;
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }

var UHW='a';

var d = new Date();
var n = d.getTime();

	UHW=prompt("To escape from slender, type in a minute\nI am the Saviour of my world\nHTML is my body, and CGI is my blood\nI have traversed endless dimensions and millions of terabytes\nUnaware of packet loss, Nor aware of TCP\nHave hacked to death to bring justice to everyone\nYet, those works will never speak of me\nFor I am Anonymous\nSo as I pray, Unlimited Hacking Works");

var f = new Date();
var m = f.getTime();

if ((m-n)>60000)
{
		alert("A self-proclaimed hacker with slow hands?\nSociety doesn't need you!");
		setTimeout(function(){window.location.replace("dead.cgi");}, 5000);
}
else
{
	if (UHW=='a')
	{
		alert("A self-proclaimed hacker with slow hands?\nSociety doesn't need you!");
		setTimeout(function(){window.location.replace("dead.cgi");},5000);
	}
	else if (UHW=="I am the Saviour of my world HTML is my body, and CGI is my blood I have traversed endless dimensions and millions of terabytes Unaware of packet loss, Nor aware of TCP Have hacked to death to bring justice to everyone Yet, those works will never speak of me For I am Anonymous So as I pray, Unlimited Hacking Works")
	{
		alert("You have escaped slender");
		setTimeout(function(){post('scene10.cgi', {'scene10.cgi': count});},5000);
	}
	else
	{
		alert("A self-proclaimed hacker with slow hands?\nSociety doesn't need you!");
		setTimeout(function(){window.location.replace("dead.cgi");},5000);
	}
}
}

var christina;
function display11(slot)
{

	var name = "linenum=";
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }
//	alert(count);
	switch (count)
	{
		case 0:	
			document.getElementById("textField1").value = "Today, I have another a treat for you- I want you to hack something for me. Don\'t ask why- you know its for the lulz. Nah, because I wan\'t to hack through the gate.";
			break;
		case 1:
			document.getElementById("textField1").value = "Now the target is CERN. I already put the organization\'s username there. Access their account and I will take the rest from here,";
			break;
		case 2:
		{
			document.getElementById("textField1").value = "though I must warn you, make sure they are right before you give them to me.";
			break;
		}
		case 3:
		{
			christina=prompt("587a7cb820dc51445b3a9a2985133c6f");
			if (christina=="El Psy Congroo")
			{
				alert("Good Job! I owe you 2 favors.");
		setTimeout(function(){post('scene11plus.cgi', {'scene11plus.cgi': slot});},5000);
			}
			else
			{
				alert("You aren't a good hacker afterall.");
				setTimeout(function(){window.location.replace("dead.cgi");}, 5000);
			}
			break;
		}
			

	}

	count++;
	document.cookie="linenum=" + count + "; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
	return 1;
}

function display12(slot)
{

	var name = "linenum=";
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }
//	alert(count);
	switch (count)
	{
		case 0:	
			document.getElementById("textField1").value = "You order coffee. You drink the beverage, stare at your work- its been like this for the past 6 hours now. You feel like you need to sleep soon, caffeine can only take someone so far until they faint.";
			break;
		case 1:
			document.getElementById("textField1").value = "GF: Hey, wanna see something interesting?";
			break;
		case 2:
		{
			document.getElementById("textField1").value = "GF: I was skimming through this webpage until I found something interesting in this file-";
			break;
		}
		case 3:
		{
			document.getElementById("textField1").value = "GF: It says \"Whenever there is a gap between where you are now and where you want to be, and you don\'t know how to find a way to cross that gap, you have a problem\"";
			break;
		}
		case 4:
		{
			document.getElementById("textField1").value = "You: Huh, I just heard a while ago, outside, that Noynoy is the source of our problem.";
			break;
		}
		case 5:
			post('scene13.cgi', {'scene13.cgi': slot});
			break;
			

	}

	count++;
	document.cookie="linenum=" + count + "; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
	return 1;
}

function display13(slot)
{
	var juliet;
	var name = "linenum=";
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }
//	alert(count);
	switch (count)
	{
	 
		case 0:	
		{
			document.getElementById("textField1").value = "Voice: Your 4th challenge is simple. Solve this riddle that I will give to you and you are one step closer to freedom.";
			break;
		}
		case 1:
		{
			juliet=prompt("A smooth dance, a ball sport, an Asian country, a girl's name. What's her name?");
			if (juliet=="Juliet")
			{
				document.getElementById("textField1").value = "Yes, Juliet, a nice name. You've earned 2 favors from me.";
				setTimeout(function(){	post('scene13plus.cgi', {'scene13plus.cgi': slot});}, 5000);
			}
			else
			{
				alert("Eengk.. Wrong!\n-2 Health");
				post('scene13minus.cgi', {'scene13minus.cgi': slot});
			}
			break;
		}
	}

	count++;
	document.cookie="linenum=" + count + "; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
	return 1;
}

function display14(health)
{
	var life;
	var name = "linenum=";
	var i;
	var type;
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }
//	alert(count);
	switch (count)
	{
		case 0:	
		{
			document.getElementById("textField1").value = "Voice: Since this is our last game I decided to make it special. I have invited a lady friend of yours- Juliet do you recall her.";
			break;
		}
		case 1:	
		{
			document.getElementById("textField1").value = "GF: Boy help me, this psycho has me strapped and theres a timer on the wall- oh god its poison gas. <cough> please help me I\'m dying I l..";
			break;
		}
		case 2:	
		{
			document.getElementById("textField1").value = "Voice: Your challenge, should you accept it, would be to rescue your damsel in distress.";
			break;
		}
		case 3:	
		{
			document.getElementById("textField1").value = "Voice: The room she is held in is being pumped with poison gas- don\'t worry she is safe for now, Ive given her some antidote that should help her for 40 seconds after I stop talking.";
			break;
		}
		case 4:	
		{
			document.getElementById("textField1").value = "Voice: There is an air vent that would remove all the poison gas- problem is the program that controls it suffered an error in its code.";
			break;
		}
		case 5:	
		{
			document.getElementById("textField1").value = "Voice: You can fix it, if you are quick and accurate enough. Every error you make will damage you. Also, if the 40 seconds passes and you are still here, the shock collar would now go boom.";
			break;
		}
		case 6:	
		{
			document.getElementById("textField1").value = "You've already thought of the code. All you need to do is to type it in the computer.";
			break;
		}
		case 7:
		{
			var d = new Date();
			var n = d.getTime();
			
			for (i=0; i<health; i++)
			{
				life=health-i;
				type=prompt("Health: "+life+"\nthrows IOException");
				if (type=="throws IOException")
					break;
				
			}
			for (; i<health; i++)
			{
				life=health-i;
				type=prompt("Health: "+life+"\nthrows MathErrorException");
				if (type=="throws MathErrorException")
					break;
			}
			for (; i<health; i++)
			{
				life=health-i;
				type=prompt("Health: "+life+"\nthrows ArrayOutOfBoundException");
				if (type=="throws ArrayOutOfBoundException")
					break;
			}
			for (; i<health; i++)
			{
				life=health-i;
				type=prompt("Health: "+life+"\nthrows EventException");
				if (type=="throws EventException")
					break;
			}
			for (; i<health; i++)
			{
				life=health-i;
				type=prompt("Health: "+life+"\nthrows WarningException");
				if (type=="throws WarningException")
					break;
			}
			for (; i<health; i++)
			{
				life=health-i;
				type=prompt("Health: "+life+"\nDignitas throws at Baron Pit");
				if (type=="Dignitas throws at Baron Pit")
					break;
			}
			var f = new Date();
			var v = f.getTime();

			if (i==health)
			{
				document.getElementById("textField1").value = "Voice: You should have just chosen to leave. Seems like the title \"Hero of Justice\" does not fit you. Farewell. GGWP";
				setTimeout(function(){window.location.replace("dead.cgi");},5000);
			}
			else if ((v-n)>=40000)
			{
				document.getElementById("textField1").value = "Voice: You should have just chosen to leave. Seems like the title \"Hero of Justice\" does not fit you. Farewell. GGWP";
				setTimeout(function(){window.location.replace("dead.cgi");},5000);
			}
			else
			{
				document.getElementById("textField1").value = "Voice: Ah, you managed to save her, I should have given you only 10 seconds. Anyway, all the gas is out and the straps are released. ";
				setTimeout(function(){window.location.replace("survive.cgi");},5000);
			}
	
			break;
		}
		case 8:	
		{
			document.getElementById("textField1").value = "Some ammonia would be released into the air and some adrenaline would be injected into her and she would be awake soon.";
			break;
		}
		case 9:	
		{
			setTimeout(function(){window.location.replace("dead.cgi");},5000);
			break;
		}

	}

	count++;
	document.cookie="linenum=" + count + "; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
	return 1;
}


function post(path, params, method) {
    method = method || "post"; // Set method to post by default if not specified.

    // The rest of this code assumes you are not using a library.
    // It can be made less wordy if you use one.
    var form = document.createElement("form");
    form.setAttribute("method", method);
    form.setAttribute("action", path);

    for(var key in params) {
        if(params.hasOwnProperty(key)) {
            var hiddenField = document.createElement("input");
            hiddenField.setAttribute("type", "hidden");
            hiddenField.setAttribute("name", key);
            hiddenField.setAttribute("value", params[key]);

            form.appendChild(hiddenField);
         }
    }

    document.body.appendChild(form);
    form.submit();
}


function hope()
{

	var name = "linenum=";
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }
//	alert(count);
	switch (count)
	{
		case 0:	
			document.getElementById("textField1").value = "Voice: You are now free to go Boy.";
			break;
		case 1:
			document.getElementById("textField1").value = "Don\'t worry, I wont chase you anymore.";
			break;
		case 2:
			document.getElementById("textField1").value = "Aside from that little bit of treachery at the beginning I have been true to my words.";
			break;
		case 3:
			document.getElementById("textField1").value = "Now go, follow the road outside and never come back. ";
			break;
		case 4:
			document.getElementById("textField1").value = "Oh and by the way, if you attempt anyone in this little game of ours,";
			break;
		case 5:
			document.getElementById("textField1").value = "I assure you I am more than happy and capable to play with you again.";
			break;
		case 6:
			window.location.replace("credits.cgi");
			break;

	}

	count++;
	document.cookie="linenum=" + count + "; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
	return 1;
}

function scene11()
{
	var name = "slender=";
//	alert("nandito");
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) 
		{
			var count = parseInt(c.substring(name.length,c.length), 10);
		}
    }

	post('scene11.cgi', {'scene11.cgi': count});
	
}

function createcookie()
{
	document.cookie="linenum=0; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
//	alert("DOne");
}

function createSlender(body)
{

	document.cookie="slender="+body+"; expires=Thu, 18 Dec 2014 12:00:00 UTC; path=/";
//	alert("DOne");
}


