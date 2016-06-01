# Update apt
exec { 'apt-get-update':
    command => '/usr/bin/apt-get update --yes',
}

exec { 'apt-get-upgrade':
    command => '/usr/bin/apt-get upgrade --yes',
    require => Exec['apt-get-update'],
}

Package { ensure => 'installed' }

$packages = [
        'vim',
        'xubuntu-desktop',
        'build-essential',
        'firefox',
    ]

package { $packages: 
    install_options => ['--no-install-recommends'],
    require => Exec['apt-get-upgrade'],
}

#exec { 'virtualbox-additions':
    #command => '/usr/bin/yes | /vagrant/VBoxLinuxAdditions.run',
    #returns => 1
#} ->

exec { 'apt-get-clean':
    command => '/usr/bin/apt-get clean',
    require => Package[$packages],
}
