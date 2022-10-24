# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Christer Edwards <christer.edwards@gmail.com>
# Contributor: zer0def <zer0def@github>

pkgname=salt
pkgver=3005.1
pkgrel=1

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
        "fix-entrypoint.patch::https://github.com/saltstack/salt/commit/b676e6338a7c094cb3335d11f851ac0e12222017.patch"
        salt.logrotate)

sha256sums=('fa14c5d873f863b50950121d7e23a2449502745490c7c48c0cf045406cfe57c1'
            '219f23ddd44003c8572201495834cf8d84967b182d29157fa3ce73270785b7ab'
            'abecc3c1be124c4afffaaeb3ba32b60dfee8ba6dc32189edfa2ad154ecb7a215')

prepare() {
  cd salt-$pkgver
  sed -i '/^contextvars/d' requirements/base.txt

  # remove version requirements for pyzmq, there's no point in it
  # we only have one version and the "python_version <=> *" checks are discarded
  # so pyzmq<=20.0.0 ends up in the final requirements.txt
  echo -e '-r crypto.txt\n\npyzmq' > requirements/zeromq.txt

  patch -Np1 < "$srcdir/fix-entrypoint.patch"
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
