# Contributor: Thomas S Hatch <thatch45@gmail.com>

pkgname=varch
pkgver=0.8.3
pkgrel=1
pkgdesc="ArchLinux virtual machine builder"
arch=(any)
url="http://code.google.com/p/varch/"
license=("GPL3")
depends=('python>=3.1'
         'multipath-tools'
         'aif'
         'qemu')
optdepends=('virtualbox: To enable support for virtualbox vdi images'
            'libvirtd: To use generated virtual machines with libvirt'
            'qemu-kvm: Run kvm virtual machines')
options=(!emptydirs)
source=("http://varch.googlecode.com/files/${pkgname}-${pkgver}.tar.gz")
md5sums=('2b1b490bf326c9ea5d416c2cb676eb3d')

package() {
  cd ${srcdir}/${pkgname}-${pkgver}
  python setup.py install --root=${pkgdir}/ --optimize=1
}
        
