# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Limao Luo <luolimao+AUR@gmail.com>
# Contributor: Wes Brown <wesbrown18@gmail.com>

pkgname=volatility3
pkgver=2.4.1
pkgrel=2
pkgdesc='Advanced memory forensics framework'
url='https://github.com/volatilityfoundation/volatility3/wiki'
arch=('any')
license=('custom')
depends=(
  'python' 'python-yara' 'python-capstone' 'python-jsonschema'
  'python-pycryptodome' 'python-pefile' 'python-snappy')
makedepends=('python-setuptools' 'python-build' 'python-installer' 'python-wheel')
provides=('volatility')
replaces=('volatility')
source=(https://github.com/volatilityfoundation/volatility3/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('5f785a778654b76fc85b7b82b2e9ba9e6315a99169d4d956a9af84ae91086e7a38cac343b7df0f00d6830361c77d377408bf8eab3679c161c8a02212c696389c')
b2sums=('7f00ec6b57eb9ef6420f4c1aa735203fbd51fca39aa13200eb821d13842f879c8743f63da7c5bbcf7d84a2850709a15c0aadc2b0311edbdf34dfa026f2a3dcd6')

build() {
  cd ${pkgname}-${pkgver}
  python -m build --wheel --no-isolation
}

package() {
  cd ${pkgname}-${pkgver}
  python -m installer --destdir="${pkgdir}" dist/*.whl
  install -Dm 644 README.md -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 644 LICENSE.txt -t "${pkgdir}/usr/share/licenses/${pkgname}"
}

# vim: ts=2 sw=2 et:
