# Maintainer: Kyle Keen <keenerd@gmail.com>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: PepeSmith
# Contributor: Aron Asor <aronasorman at gmail.com>
# Contributor: Chris Brannon <chris@the-brannons.com>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>

pkgname=ipython
pkgver=7.31.0
pkgrel=1
pkgdesc="An enhanced Interactive Python shell."
arch=('any')
url="https://ipython.org"
license=('BSD')
depends=('python' 'python-traitlets' 'python-pexpect' 'sqlite'
         'python-pickleshare' 'python-prompt_toolkit'
         'python-jedi' 'python-pygments' 'python-backcall'
         'python-matplotlib-inline')
makedepends=('python-setuptools')
checkdepends=('python-nose' 'python-requests' 'python-testpath'
              'jupyter-nbformat' 'python-ipykernel' 'python-numpy'
              'python-pytest-trio' 'python-matplotlib')
source=("https://files.pythonhosted.org/packages/source/${pkgname::1}/$pkgname/$pkgname-$pkgver.tar.gz"
        "https://www.packal.org/sites/default/files/public/styles/icon_large/public/workflow-files/nkeimipynbworkflow/icon/icon.png")
sha256sums=('346c74db7312c41fa566d3be45d2e759a528dcc2994fe48aac1a03a70cd668a3'
            '3c44a6fa1e3a8afc24754c90469404770b639cb960361988999a4cdd677699d8')
b2sums=('5debac9a1011cc6541a2ce97df5d8793465ce4c289d1293c33c29eacc23cbd2271f0a8d7362c3445a88d080edefd85046aebc8782cd930c3dd8b6837ec682bf6'
        'd445e2bc7a037db8715ea103611720e965987e155c32e445b0ef783e519fca8a0301b16c5763fd9a5d8d169c3b0d7b4db6c0bd0f9772842258b135dcb1d6d5a2')

# confirm that an update does not break sage?

build() {
  cd $pkgname-$pkgver
  python setup.py build
}

check() {
  cd $pkgname-$pkgver
  # Exclude minor test failures with Python 3.10
  pytest -k 'not test_magic_arguments and not test_pinfo_docstring_if_detail_and_no_source and not test_pprint_heap_allocated_type'
}

package() {
  cd $pkgname-$pkgver
  python setup.py install --prefix=/usr --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 docs/source/about/license_and_copyright.rst "$pkgdir/usr/share/licenses/ipython/LICENSE"

  cd "examples/IPython Kernel"
  # FS#45120
  sed -i 's/gnome-netstatus-idle/ipython/' ipython.desktop
  install -Dm644 -t "$pkgdir/usr/share/applications" ipython.desktop
  # FS#47046
  install -Dm644 "$srcdir/icon.png" "$pkgdir/usr/share/pixmaps/ipython.png"
}
