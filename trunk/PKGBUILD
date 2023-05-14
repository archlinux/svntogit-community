# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Contributor: Johannes Dewender  arch at JonnyJD dot net
# Contributor: Ivan Sichmann Freitas <ivansichfreitas@gmail.com>
# Contributor: Brice Maron <brice@bmaron.net>
# Contributor: Nuno Araujo <nuno.araujo at russo79.com>
# Contributor: Steven Allen <steven {at} stebalien {dot} com>

pkgname=python-keyring
_name=keyring
pkgver=23.13.1
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
sha512sums=('7e56380e7311a31d8703b9e3beb74a8c8ce026f6cf9e1792780d349f3db61f50a1905c7d509a7013dd7cb47428dd3c28c3620815f01d3c4dbd7f648e056539d0')
b2sums=('fb39490ba857f97b9b89856059664dfe21495ffe651bb48ad4e2284efe3f3c7551d34bfb4c39518c2b9b5e31e61b91693301271750f4ec837567d7652b11e9ef')

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
