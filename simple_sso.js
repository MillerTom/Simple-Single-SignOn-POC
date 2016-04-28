(function($){
  $(document).ready(function(){
    var username = Drupal.settings.simple_sso.username;
    var key = Drupal.settings.simple_sso.sso_key;
    var sops = 'http://tbayenv-sops.info/simple-sso-client/' + username + '/' + key;;
    var qms = 'http://tbayenv-qms.info/simple-sso-client/' + username + '/' + key;

    $('a[href="http://tbayenv-sops.info"]').attr('href', sops);
    $('a[href="http://tbayenv-qms.info"]').attr('href', qms);
  });
})(jQuery);