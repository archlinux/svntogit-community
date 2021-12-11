# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Limao Luo <luolimao+AUR@gmail.com>

pkgbase=python-pbr
pkgname=(python-pbr python2-pbr)
pkgver=5.8.0
pkgrel=1
pkgdesc="Python Build Reasonableness"
arch=('any')
url='https://pypi.python.org/pypi/pbr'
license=('Apache')
makedepends=('python2-setuptools' 'python-setuptools' 'git')
checkdepends=('python-stestr' 'python-testscenarios' 'python-testresources' 'python-testrepository'
              'python-mock' 'python-virtualenv' 'python-wheel' 'python-sphinx')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/openstack-dev/pbr/archive/$pkgver.tar.gz")
sha512sums=('221ec7eca278d3f6694958f966c0819a97143fe87b95fd786607eb3b8cf825ce82df70a74808b9a5904827b7008ce094b52cf579641cc347cdb193881a07de45')

export PBR_VERSION=$pkgver

prepare() {
  sed -i 's/virtualenv.create_environment(path, clear=True)/virtualenv.cli_run([path, "--clear"])/' pbr-$pkgver/pbr/tests/test_packaging.py

  cp -a pbr-$pkgver{,-py2}

  find pbr-$pkgver-py2 -name \*.py -exec sed -i '1s/python$/&2/' {} +
}

build() {
  cd "$srcdir"/pbr-$pkgver
  python setup.py build

  cd "$srcdir"/pbr-$pkgver-py2
  python2 setup.py build
}

check() {
  cd pbr-$pkgver
  stestr run
}

package_python-pbr() {
  depends=('python-setuptools')

  cd pbr-$pkgver
  python setup.py install -O1 --root="$pkgdir"
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

package_python2-pbr() {
  depends=('python2-setuptools')

  cd pbr-$pkgver-py2
  python2 setup.py install -O1 --root="$pkgdir"
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE

  mv "$pkgdir"/usr/bin/pbr{,2}
}
