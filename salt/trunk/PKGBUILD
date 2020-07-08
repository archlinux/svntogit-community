# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: Sébastien Luttringer
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Christer Edwards <christer.edwards@gmail.com>

pkgname=salt
pkgver=2019.2.4
pkgrel=1

pkgdesc='Central system and configuration manager'
arch=('any')
url='http://saltstack.org/'
license=('Apache')

replaces=('salt-zmq' 'salt-raet')
conflicts=('salt-zmq' 'salt-raet')

depends=('python2-jinja'
         'python2-msgpack'
         'python2-yaml'
         'python2-markupsafe'
         'python2-requests'
         'python2-pyzmq'
         'python2-crypto'
         'python2-m2crypto'
         'python2-systemd'
         'python2-tornado'
         'python2-futures')
optdepends=('dmidecode: decode SMBIOS/DMI tables'
            'python2-pygit2: gitfs support')

backup=('etc/logrotate.d/salt'
        'etc/salt/master'
        'etc/salt/minion')

install=salt.install
source=("https://pypi.io/packages/source/s/salt/salt-$pkgver.tar.gz"
        salt.logrotate)

sha256sums=('afeb1c95db61c9008f95259c0b27e525c8a9957cbc6f51c40e824a92637d2847'
            'abecc3c1be124c4afffaaeb3ba32b60dfee8ba6dc32189edfa2ad154ecb7a215')

build() {
  cd salt-$pkgver
  python2 setup.py build
}

package() {
  install -Dm644 salt.logrotate "$pkgdir"/etc/logrotate.d/salt

  cd salt-$pkgver
  python2 setup.py --salt-pidfile-dir="/run/salt" install --root="$pkgdir" --optimize=1 --skip-build

  # default config
  install -Dm644 conf/master "$pkgdir/etc/salt/master"
  install -Dm644 conf/minion "$pkgdir/etc/salt/minion"

  # systemd services
  for _svc in salt-master.service salt-syndic.service salt-minion.service salt-api.service; do
    install -Dm644 pkg/$_svc "$pkgdir/usr/lib/systemd/system/$_svc"
  done
  install -Dm644 pkg/salt.bash "$pkgdir/usr/share/bash-completion/completions/salt"
  install -Dm644 pkg/zsh_completion.zsh "$pkgdir/usr/share/zsh/site-functions/_salt"
}

# vim:set ts=2 sw=2 et:
