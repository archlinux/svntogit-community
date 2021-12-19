# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Christer Edwards <christer.edwards@gmail.com>
# Contributor: zer0def <zer0def@github>

pkgname=salt
pkgver=3004
pkgrel=4

pkgdesc='Central system and configuration manager'
arch=('any')
url='http://saltstack.org/'
license=('Apache')

replaces=('salt-zmq' 'salt-raet')
conflicts=('salt-zmq' 'salt-raet')

depends=('python-jinja'
         'python-msgpack'
         'python-yaml'
         'python-markupsafe'
         'python-requests'
         'python-pyzmq'
         'python-m2crypto'
         'python-systemd'
         'python-distro'
         'python-importlib-metadata'
         'python-pycryptodomex')
optdepends=('dmidecode: decode SMBIOS/DMI tables'
            'python-pygit2: gitfs support')
#checkdepends=('python-pytest' 'python-psutil')

backup=('etc/logrotate.d/salt'
        'etc/salt/master'
        'etc/salt/minion')

install=salt.install
source=("https://pypi.io/packages/source/s/salt/salt-$pkgver.tar.gz"
        "patch-requirements.patch::https://github.com/saltstack/salt/commit/be9879c5d5b30ea0997b1cfca9ad830a54a900b0.patch"
        salt.logrotate)

sha256sums=('3d53561bc86e014dca2ec3dc981079be04d55ea047890cabde25e5b10bfa5b13'
            '84e9f80f684a3d7059e8a3636ec67f3d088c6250643ee17e58fb0032f2ef84a0'
            'abecc3c1be124c4afffaaeb3ba32b60dfee8ba6dc32189edfa2ad154ecb7a215')

prepare() {
  cd salt-$pkgver
  patch -Np1 < "$srcdir/patch-requirements.patch"
  sed -i '/^contextvars/d' requirements/base.txt
}

build() {
  cd salt-$pkgver
  python setup.py build
}

# TODO: Missing salt-factories, pytest-tempdir
# check() {
#   cd salt-$pkgver
#   python setup.py install --root="$PWD/tmp_install" --optimize=1
#   PYTHONPATH="$PWD/tmp_install/usr/lib/python3.10/site-packages:$PYTHONPATH" py.test
# }

package() {
  install -Dm644 salt.logrotate "$pkgdir"/etc/logrotate.d/salt

  cd salt-$pkgver

  python setup.py --salt-pidfile-dir="/run/salt" install --root="$pkgdir" --optimize=1 --skip-build

  # default config
  install -v -Dm644 conf/master "$pkgdir/etc/salt/master"
  install -v -Dm644 conf/minion "$pkgdir/etc/salt/minion"

  # systemd services
  for _svc in salt-master.service salt-syndic.service salt-minion.service salt-api.service; do
    install -v -Dm644 pkg/$_svc "$pkgdir/usr/lib/systemd/system/$_svc"
  done
  install -v -Dm644 pkg/salt.bash "$pkgdir/usr/share/bash-completion/completions/salt"
  install -v -Dm644 pkg/salt.zsh "$pkgdir/usr/share/zsh/site-functions/_salt"
  install -v -Dm644 -t "$pkgdir/usr/share/fish/vendor_completions.d" pkg/fish-completions/*
}

# vim:set ts=2 sw=2 et:
