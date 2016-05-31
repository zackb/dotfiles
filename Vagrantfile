# -*- mode: ruby -*-
# vi: set ft=ruby :

VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
  config.vm.box 	= 'ubuntu/trusty64'
  config.vm.box_url = 'ubuntu/trusty64'

  config.vm.hostname = 'zackb'
  config.vm.base_mac = '08002702C8D0'

  config.ssh.username = 'vagrant'

  config.vm.network "forwarded_port", guest: 9200, host: 9200
  config.vm.network "forwarded_port", guest: 9300, host: 9300

  config.vm.provider "virtualbox" do |v|
    v.name = 'zackb'
    v.gui  = true
    v.memory = 2048
  end

  config.vm.provision :puppet do |puppet|
    puppet.manifests_path = 'puppet/manifests'
	puppet.manifest_file  = 'zackb.pp'
  end

end
