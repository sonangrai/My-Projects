$(document).ready(function()
{

  $(window).scroll(function ()
  {
    console.log($(window).scrollTop())
    if ($(window).scrollTop() > 280)
     {
      $('#myheader').addClass('navbar-fixed');
    }
    if ($(window).scrollTop() < 281)
    {
      $('#myheader').removeClass('navbar-fixed');
    }
  });
});
