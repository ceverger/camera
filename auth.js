function auth()
{
	person = { login: "login", password: "password" };
	
	person.login = document.forms["Data"]["Login"].value;
	person.password = document.forms["Data"]["Password"].value;

	json = JSON.stringify(person);

	requestAuth(json);
}

function requestAuth(request)
{
	const xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function () { 
		if(xhttp.readyState == 4)
		{
			json = this.responseText;
			response = JSON.parse(json);
			if(response.status == "false")
			{
				window.location.assign("error.html");
			}
			else
			{
				window.location.assign("settings.html");
			}
		}
	}
	
	xhttp.open("POST", "auth.cgi", true);
	xhttp.send(request);
}
