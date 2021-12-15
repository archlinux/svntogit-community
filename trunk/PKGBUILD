# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Limao Luo <luolimao+AUR@gmail.com>

pkgname=python-pbr
pkgver=5.8.0
pkgrel=2
pkgdesc="Python Build Reasonableness"
arch=('any')
url='https://pypi.python.org/pypi/pbr'
license=('Apache')
depends=('python-setuptools')
checkdepends=('python-stestr' 'python-testscenarios' 'python-testresources' 'python-testrepository'
              'python-mock' 'python-virtualenv' 'python-wheel' 'python-sphinx' 'git')
source=("$pkgname-$pkgver.tar.gz::https://github.com/openstack-dev/pbr/archive/$pkgver.tar.gz")
sha512sums=('221ec7eca278d3f6694958f966c0819a97143fe87b95fd786607eb3b8cf825ce82df70a74808b9a5904827b7008ce094b52cf579641cc347cdb193881a07de45')

export PBR_VERSION=$pkgver

prepare() {
  sed -i 's/virtualenv.create_environment(path, clear=True)/virtualenv.cli_run([path, "--clear"])/' pbr-$pkgver/pbr/tests/test_packaging.py
}

build() {
  cd "$srcdir"/pbr-$pkgver
  python setup.py build
}

check() {
  cd pbr-$pkgver
  stestr run
}

package() {
  cd pbr-$pkgver
  python setup.py install -O1 --root="$pkgdir"
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
