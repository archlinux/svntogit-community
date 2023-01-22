# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Contributor: Johannes Dewender  arch at JonnyJD dot net
# Contributor: Ivan Sichmann Freitas <ivansichfreitas@gmail.com>
# Contributor: Brice Maron <brice@bmaron.net>
# Contributor: Nuno Araujo <nuno.araujo at russo79.com>
# Contributor: Steven Allen <steven {at} stebalien {dot} com>

pkgname=python-keyring
_name=keyring
pkgver=23.11.0
pkgrel=1
pkgdesc='Store and access your passwords safely'
arch=('any')
url='https://github.com/jaraco/keyring'
license=('PSF' 'MIT')
depends=('python-jaraco.classes' 'python-jeepney' 'python-secretstorage' 'python-importlib-metadata')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
checkdepends=('python-pytest-flake8' 'python-pytest-runner' 'python-pytest-black' 'python-pytest-cov' 'python-pytest-mypy')
optdepends=('python-keyrings-alt: Alternative backends'
            'python-dbus: kwallet backend')
source=(https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz)
sha512sums=('8693acad1d4cb0499adee362db81689131a587a03bfcbb1e518f4ca85abd71c4d3a987c7a70dc577c6649f412fa5b075dcb3439ba7c209bff5edb1c302277586')
b2sums=('33d68b0e274f9cf400b5e274b77734a44e5f4ebf374a74790b39428f3a01cf05499f1cf40b38f1da426ff3e1a4ad98ae5e733ad640f0b180d78772708f773c74')

build() {
  cd $_name-$pkgver

  python -m build
}

check() {
  cd $_name-$pkgver

  python -m pytest
}

package() {
  cd $_name-$pkgver

  python -m installer -d "$pkgdir" dist/*.whl
  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE

  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  rm -rf "$pkgdir"/$site_packages/keyring/tests
}

# vim:set ts=2 sw=2 et:
