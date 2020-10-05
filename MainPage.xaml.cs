using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

using System.Net;
using System.Net.Http;
using System.IO;
using System.Threading;

namespace TV_Remote
{
    public partial class MainPage : ContentPage
    {
        private string IP = "http://192.168.1.183/";
        private static readonly HttpClient client = new HttpClient();


        public MainPage()
        {
            InitializeComponent();

        }

        void Power(object sender, EventArgs e)
        {
            doHttpReq("Power");
        }
        void Aspect(object sender, EventArgs e)
        {
            doHttpReq("Aspect");
        }
        void Source(object sender, EventArgs e)
        {
            doHttpReq("Source");
        }
        void Mute(object sender, EventArgs e)
        {
            doHttpReq("Mute");
        }
        void Menu(object sender, EventArgs e)
        {
            doHttpReq("Menu");
        }
        void VolumeUp(object sender, EventArgs e)
        {
            doHttpReq("VolumeUp");
        }

        void VolumeDown(object sender, EventArgs e)
        {
            doHttpReq("VolumeDown");
        }

        void ChannelUp(object sender, EventArgs e)
        {
            doHttpReq("ChUp");
        }
        void ChannelDown(object sender, EventArgs e)
        {
            doHttpReq("ChDown");
        }
        void Ok (object sender, EventArgs e)
        {
            doHttpReq("Ok");
        }
        void KeyDown(object sender, EventArgs e)
        {
            doHttpReq("Down");
        }
        void KeyUp(object sender, EventArgs e)
        {
            doHttpReq("Up");
        }
        void KeyLeft(object sender, EventArgs e)
        {
            doHttpReq("Left");
        }
        void KeyRight(object sender, EventArgs e)
        {
            doHttpReq("Right");
        }
        void Ch1(object sender, EventArgs e)
        {
            doHttpReq("1");
        }
        void Ch2(object sender, EventArgs e)
        {
            doHttpReq("2");
        }
        void Ch3(object sender, EventArgs e)
        {
            doHttpReq("3");
        }
        void Ch4(object sender, EventArgs e)
        {
            doHttpReq("4");
        }
        void Ch5(object sender, EventArgs e)
        {
            doHttpReq("5");
        }
        void Ch6(object sender, EventArgs e)
        {
            doHttpReq("6");
        }
        void Ch7(object sender, EventArgs e)
        {
            doHttpReq("7");
        }
        void Ch8(object sender, EventArgs e)
        {
            doHttpReq("8");
        }
        void Ch9(object sender, EventArgs e)
        {
            doHttpReq("9");
        }
        void Ch0(object sender, EventArgs e)
        {
            doHttpReq("0");
        }
        public void doHttpReq( string requestCommand)
        {
            // Create a request for the URL.
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(IP + requestCommand);
            // If required by the server, set the credentials.
            request.Credentials = CredentialCache.DefaultCredentials;
            request.GetResponseAsync();
        }
    }
}

