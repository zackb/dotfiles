# -*- mode: ruby -*-
# vi: set ft=ruby :

VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
  config.vm.box 	= 'ubuntu/trusty32'
  config.vm.box_url = 'ubuntu/trusty32'

  config.vm.hostname = 'zackb'
  config.vm.base_mac = '08002702C8D0'

  config.ssh.username = 'vagrant'

  config.vm.provider "virtualbox" do |v|
    v.gui  = true
    v.name = 'zackb'
  end

  config.vm.provision :puppet do |puppet|
    puppet.manifests_path = 'puppet/manifests'
	puppet.manifest_file  = 'zackb.pp'
  end

end
