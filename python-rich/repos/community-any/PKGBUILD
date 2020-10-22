# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Hao Long <imlonghao@archlinuxcn.org>

pkgname=python-rich
_name=rich
pkgver=9.0.1
pkgrel=2
pkgdesc='Render rich text, tables, progress bars, syntax highlighting, markdown and more to the terminal'
arch=(any)
url='https://github.com/willmcgugan/rich'
license=('MIT')
depends=('python-colorama' 'python-pygments' 'python-typing_extensions' 'python-commonmark')
makedepends=('python-setuptools' 'python-dephell')
source=("https://github.com/willmcgugan/rich/archive/v${pkgver}/rich-${pkgver}.tar.gz"
        "https://github.com/willmcgugan/rich/commit/cbac633ab30f3b3e4e836ff87a3a88a28bffca48.patch")
b2sums=('03304eab96beb683833efcacf3b15548d23850210bb06275fab78b8e76e4351f0b2d5e00e87ea8c4c3d8281a050c63ad636e214ce38b11d3906641071163bd46'
        '9a7e358673c9c051f040beb96b5a85ac4718f7bc9ff820c04ebee7c84b0646361096c439b4fc86e91d67af31017a25dd6d1103f5f7657e545b86b89b85a6b65c')

prepare() {
  cd rich-${pkgver}
  patch -Np1 < ../cbac633ab30f3b3e4e836ff87a3a88a28bffca48.patch
  dephell deps convert --from pyproject.toml --to setup.py
}

build() {
  cd rich-${pkgver}
  python3 setup.py build
}

package() {
  cd rich-${pkgver}
  python3 setup.py install --root="${pkgdir}" --optimize=1 --skip-build
  install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}
